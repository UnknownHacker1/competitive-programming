/*
 * Make The Fence Great Again  [1221D]
 * Problem:  https://codeforces.com/problemset/problem/1221/D
 * Verdict:  ACCEPTED        Solved: 2022-06-16
 * Language: C++20 (GCC 11-64)
 * Runtime:  140 ms     Memory: 44600 KB
 * Tags:     dp
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1221/submission/160896304
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
ll dp[(int)3e5+3][3];
ll a[(int)3e5+3],b[(int)3e5+3];
int n;
ll rec(int idx, int add){
    if(idx==n)return 0;
    if(dp[idx][add]!=-1)
        return dp[idx][add];
    ll ret = 1e18;
    for(ll i = 0; i <= 2; i++){
        if(idx&&a[idx-1]+add==a[idx]+i)continue;
        ret=min(ret,rec(idx+1,i)+b[idx]*i);
    }
    return dp[idx][add]=ret;
}
int main()
{
    ACPLS(); 
tc{
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j]=-1;
        }
    }
    for(int i = 0; i < n; i++)
        cin>>a[i]>>b[i];
    cout<<rec(0,0)<<'\n';
}
}