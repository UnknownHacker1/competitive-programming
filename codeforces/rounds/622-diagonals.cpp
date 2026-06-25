/*
 * Diagonals  [1995A]
 * Problem:  https://codeforces.com/problemset/problem/1995/A
 * Verdict:  ACCEPTED        Solved: 2025-03-15
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 100 KB
 * Tags:     brute force, greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1995/submission/310793528
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
        int n,k;
        cin>>n>>k;
        vector<int>dags; 
        for(int i = 1; i < n; i++)dags.push_back(i),dags.push_back(i);
        dags.push_back(n);
        int ans = 0;
        while(k){
            k -= min(k, dags.back());
            dags.pop_back();
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}