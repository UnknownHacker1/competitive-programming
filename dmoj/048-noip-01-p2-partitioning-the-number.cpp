/*
 * NOIP '01 P2: Partitioning the Number  [noip01p2]
 * Problem:  https://dmoj.ca/problem/noip01p2
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-12-08
 * Language: C++20
 * Runtime:  0.023430332 s     Memory: 11240.0 KB
 * Source:   https://dmoj.ca/src/5100529
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
ll dp[1000][1000];
ll solve(int n, int k){
    if(k == 0 && n == 0){
        return 1;
    }
    if(k == 0 || n == 0){
        return 0;
    }
    if(dp[n][k]!=-1)return dp[n][k];
    ll ret = (n >= k ? solve(n - k, k) : 0);
    return dp[n][k]=ret + solve(n - 1, k - 1);
}
int main()
{
    ACPLS();  
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
}