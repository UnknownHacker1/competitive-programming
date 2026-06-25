/*
 * Red-Black Number  [1593F]
 * Problem:  https://codeforces.com/problemset/problem/1593/F
 * Verdict:  ACCEPTED        Solved: 2021-10-15
 * Language: C++17 (GCC 7-32)
 * Runtime:  202 ms     Memory: 16100 KB
 * Tags:     dfs and similar, dp, implementation, math, meet-in-the-middle
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1593/submission/132013422
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int n,a,b;
int s[45];
int dp[45][45][45][45];
int rec(int idx, int acnt, int amod, int bmod){
    if(idx==n){
        if(amod!=0||bmod!=0||acnt==n||acnt==0)
            return 1e9;
        return abs(n-acnt*2);
    }
    if(dp[idx][acnt][amod][bmod]!=-1)
        return dp[idx][acnt][amod][bmod];
    int op1=rec(idx+1,acnt+1,(amod*10+s[idx])%a,bmod);
    int op2=rec(idx+1,acnt,amod,(bmod*10+s[idx])%b);
    return dp[idx][acnt][amod][bmod]=min(op1,op2);
}
void build(int idx, int acnt, int amod, int bmod){
    if(idx==n)
        return;
    int op1=rec(idx+1,acnt+1,(amod*10+s[idx])%a,bmod);
    int op2=rec(idx+1,acnt,amod,(bmod*10+s[idx])%b);
    if(op1<op2){
        cout<<'R';
        build(idx+1,acnt+1,(amod*10+s[idx])%a,bmod);
    }
    else {
        cout<<'B';
        build(idx+1,acnt,amod,(bmod*10+s[idx])%b);
    }
}
int main()
{
    ACPLS();
tc{
    memset(dp,-1,sizeof(dp));
    cin>>n>>a>>b;
    for(int i = 0; i < n; i++){
        char ch;
        cin>>ch;
        s[i]=ch-'0';
    }
    int ans=rec(0,0,0,0);
    if(ans>=1e9){
        cout<<"-1\n";
        continue;
    }
    build(0,0,0,0);
    cout<<'\n';
}
}