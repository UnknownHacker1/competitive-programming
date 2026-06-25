/*
 * NOIP '05 P2: Frog  [noip05p2]
 * Problem:  https://dmoj.ca/problem/noip05p2
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-01-07
 * Language: C++20
 * Runtime:  0.14557006 s     Memory: 19036.0 KB
 * Source:   https://dmoj.ca/src/5193809
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
int dp[(int)2e6 + 5];
int main()
{ 
    ACPLS();   
    int l,s,t,m;
    cin>>l>>s>>t>>m;
    int a[m];
    for(int i = 0; i < m; i++)cin>>a[i];
    sort(a,a+m);
    if(s==t){
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans += (a[i] % s == 0);
        }
        cout<<ans<<'\n';
        return 0;
    }  
    int marked[(int)2e6+5]={0};
    marked[a[0]]=1; 
    for(int i = 0; i < m; i++){
        int diff = a[i] - (i == 0? 0 : a[i - 1]) - 100;
        if(diff >= 0){
            for(int j = i; j < m; j++)a[j]-=diff;
        }
        marked[a[i]] = 1;
    }
    for(int i = 1; i <= 2e6; i++)dp[i]=1e9;
    dp[0] = 0;
    for(int i = 1; i <= 2e6; i++){
        for(int d = s; d <= t; d++){
            if(i - d < 0)continue;
            dp[i] = min(dp[i], dp[i - d] + marked[i]);
        }
    }
    cout<<dp[a[m-1]+t+1];
}