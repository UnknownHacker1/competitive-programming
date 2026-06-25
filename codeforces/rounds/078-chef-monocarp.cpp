/*
 * Chef Monocarp  [1437C]
 * Problem:  https://codeforces.com/problemset/problem/1437/C
 * Verdict:  ACCEPTED        Solved: 2022-06-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 32100 KB
 * Tags:     dp, flows, graph matchings, greedy, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1437/submission/161492209
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
int n,t[205],dp[205][40005];
int rec(int idx, int cur){
    if(idx==n)
        return 0;
    if(dp[idx][cur]!=-1)
        return dp[idx][cur];
    if(cur>=t[idx]){
        return dp[idx][cur]=rec(idx+1,cur+1)+cur-t[idx];
    }
    return dp[idx][cur]=min(rec(idx,cur+1),rec(idx+1,cur+1)+t[idx]-cur);
}
int main()
{
    ACPLS(); 
tc{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>t[i];
    sort(t,t+n);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n*n; j++){
            dp[i][j]=-1;
        }
    }
    cout<<rec(0,1)<<'\n';
}
}
