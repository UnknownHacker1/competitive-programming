/*
 * Mishka and Interesting sum  [703D]
 * Problem:  https://codeforces.com/problemset/problem/703/D
 * Verdict:  ACCEPTED        Solved: 2025-03-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  2218 ms     Memory: 69800 KB
 * Tags:     data structures
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/703/submission/310399010
 */

#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 1e6+4;
vector<pair<int, int> > queries[maxN];
 
int arr[maxN], ans[maxN], pref[maxN];
 
struct fenwick_tree{
    int bit[maxN] = {0};
 
    void update(int pos, int val){
        for (; pos < maxN; pos |= pos+1) bit[pos] ^= val;
    }
 
    int sum(int r){
        int res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res ^= bit[r];
        return res;
    }
 
    int sum(int l, int r){
        return sum(r) ^ sum(l-1);
    }
};
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    cin >> q;
    
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries[a-1].push_back(make_pair(b-1, i));
    }
 
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1]^arr[i-1];
 
    map<int, int> last_ind;
    fenwick_tree fw;
    for (int i = n-1; i >= 0; i--){
        if (last_ind.count(arr[i]) == 1) fw.update(last_ind[arr[i]], arr[i]);
        fw.update(i, arr[i]);
        last_ind[arr[i]] = i;
 
        for (pair<int, int> query: queries[i]){
            ans[query.second] = fw.sum(i, query.first)^(pref[query.first+1]^pref[i]);
        }
    }
 
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}