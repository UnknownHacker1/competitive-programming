/*
 * Maximum Cost Permutation  [2144B]
 * Problem:  https://codeforces.com/problemset/problem/2144/B
 * Verdict:  ACCEPTED        Solved: 2025-10-17
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  93 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2144/submission/344105177
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;  

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        int freq[n+1]{}; 
        for(int i = 0; i < n; i++){
            cin>>p[i];
            ++freq[p[i]]; 
        }
        vector<int>missing;
        for(int i = 1; i <= n; i++){
            if(freq[i]==0){
                missing.push_back(i);
            }
        }
        int l = n+1, r = -1;
        if(missing.size() == 1){
            for(int i = 0; i < n; i++){
                if(p[i] == 0) p[i] = missing.front();
            }
        }
        for(int i = 0; i < n; i++){
            if(p[i] != i + 1){
                l = min(l, i);
                r = max(r, i);
            }
        }
        cout << max(0,r - l + 1) << '\n';
    }
    return 0;
}