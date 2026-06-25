/*
 * NOIP '06 P1 - Energy Necklace  [noip06p1]
 * Problem:  https://dmoj.ca/problem/noip06p1
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-01-07
 * Language: C++20
 * Runtime:  0.036461267 s     Memory: 3504.0 KB
 * Source:   https://dmoj.ca/src/5193743
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
int main()
{
    ACPLS("");  
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    int dp[2*n][2*n];
    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < 2*n; j++){
            dp[i][j]=0;
        }
    }
    for(int x = 2; x <= n; x++){
        for(int i = 0; i + x < 2*n; i++){
            //[i, i+x]
            for(int k = i + 1; k < i + x; k++){
                dp[i][i + x] = max(dp[i][i + x], 
                    dp[i][k]+dp[k][i + x]+a[i%n]*a[k%n]*a[(i+x)%n]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans=max(ans,dp[i][i+n]);
    }
    cout<<ans<<'\n';
}