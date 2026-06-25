/*
 * Yet Another Permutation Problem  [1858C]
 * Problem:  https://codeforces.com/problemset/problem/1858/C
 * Verdict:  ACCEPTED        Solved: 2023-08-15
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 900 KB
 * Tags:     constructive algorithms, greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1858/submission/218982730
 */

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 3;
int s[N];
int dp[N];
int n,m,d;
int rec(int i){
    if(dp[i]!=-1)return dp[i];
    if(i == m)
        return 0;
    return dp[i]= 1 + (s[i + 1] - s[i] - 1) / d + rec(i + 1);
}
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
        bool vis[n+1]{};
        for(int i = 1; i <= n; i++){
            if(vis[i])continue;
            vis[i]=1;
            int x = i;
            cout<<x<<' ';
            while(2*x<=n){
                x*=2;
                cout<<x<<' ';
                vis[x]=1;
            }
        }
        cout<<'\n';
    }
    return 0;
}