/*
 * Beautiful Palindromes  [2162E]
 * Problem:  https://codeforces.com/problemset/problem/2162/E
 * Verdict:  ACCEPTED        Solved: 2025-10-19
 * Language: C++20 (GCC 13-64)
 * Runtime:  124 ms     Memory: 2500 KB
 * Tags:     constructive algorithms, greedy, schedules
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2162/submission/344577096
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >>n>>k;
    vector<int> v(n), freq(n+1);
    for(int i=0; i<n; i++){
        cin >> v[i];
        freq[v[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(freq[i] == 0) {v.push_back(i); break;}
    }
    for(int i=v.size(); i<=n+k; i++){
        int tmp = 1;
        if(v[i-1] == 1 || v[i-2] == 1){
            if(v[i-1] == 2 || v[i-2] == 2){
                tmp=3;
            }
            else tmp=2;
        }
        v.push_back(tmp);

    }
    for(int i=n; i<=n+k-1; i++){
        cout << v[i] << " ";
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--)
    solve();
    return 0;
}