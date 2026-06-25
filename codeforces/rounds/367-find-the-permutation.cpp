/*
 * Find the Permutation  [2056B]
 * Problem:  https://codeforces.com/problemset/problem/2056/B
 * Verdict:  ACCEPTED        Solved: 2025-11-03
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     brute force, dfs and similar, graphs, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2056/submission/347181141
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
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;

        bool g[n][n];

        pair<int,int>a[n];
        for(int i = 0; i < n; i++){
            a[i].first=0;
            a[i].second=(i+1);
            for(int j = 0; j < n; j++){
                char ch;
                cin >> ch; 
                if(ch=='0'&&j<i||ch=='1'&&j>i)a[i].first++;
            }
        }
        sort(a,a+n),reverse(a,a+n);
        for(auto&i:a)cout<<i.second<<' ';
        cout<<'\n';
    }
    return 0;
}