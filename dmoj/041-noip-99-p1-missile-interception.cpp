/*
 * NOIP '99 P1 - Missile Interception  [noip99p1]
 * Problem:  https://dmoj.ca/problem/noip99p1
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2022-11-18
 * Language: C++20
 * Runtime:  0.028277344 s     Memory: 19048.0 KB
 * Source:   https://dmoj.ca/src/5041485
 */

/*
ID: BidoTeima
LANG: C++11
TASK: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
        #ifndef ONLINE_JUDGE
            freopen("output.txt", "w", stdout);
            freopen("input.txt", "r", stdin);
        #endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/
int n;
vector<int>a;
int dp[2005][2005];
int lis(int idx, int prev){
    if(idx==n)return 0;
    if(dp[idx][prev+1]!=-1)
        return dp[idx][prev+1];
    int ret = lis(idx+1,prev);
    if(prev == -1 || a[idx] < a[prev]){
        ret=max(ret,lis(idx+1,idx)+1);
    }
    return dp[idx][prev+1]=ret;
}
int main()
{
    ACPLS();   
    memset(dp,-1,sizeof(dp));
    int x;
    while(cin>>x)a.push_back(x);
    n=(int)a.size();
    cout<<lis(0,-1)<<'\n';
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; i++)a[i]=-a[i];
    cout<<lis(0,-1)<<'\n';
}