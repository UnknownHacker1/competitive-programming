/*
 * Card Game  [2025E]
 * Problem:  https://codeforces.com/problemset/problem/2025/E
 * Verdict:  ACCEPTED        Solved: 2025-03-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  452 ms     Memory: 7100 KB
 * Tags:     combinatorics, dp, fft, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2025/submission/310287599
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;      
const int N = 505,mod=998244353;
int dp2[N][N],dp[N][N],C[N][N];
ll mul(ll a, ll b){
    return (a*b)%mod;
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);     
    for(int i = 0; i <= 500; i++)C[i][0] = 1;
    dp2[0][0]=1;
    for(int i = 1; i <= 500; i++){
        for(int j = 0; j <= 500; j++){
            if(j > 0) dp2[i][j] += dp2[i - 1][j - 1];
            if(dp2[i][j]>=mod)dp2[i][j]-=mod;
            dp2[i][j] += dp2[i - 1][j + 1];
            if(dp2[i][j]>=mod)dp2[i][j]-=mod;
            C[i][j]=C[i-1][j];
            if(j>0) C[i][j] += C[i-1][j-1];
            if(C[i][j]>=mod)C[i][j]-=mod;
        }
    } 
    /*for(int i = 1; i <= 6; i++){
        for(int j = 0; j <= i; j++) cout << C[i][j]<<' ';
        cout<<'\n';
    }
    for(int i = 0; i <= 10; i++) cout<<dp2[i][0]<<' ';cout<<'\n';*/
    int n,m;
    cin>>n>>m;
    for(int i = 0; i <= m; i++){
        dp[1][i] = dp2[m][i];
        //cout<<dp[1][i]<<' ';
    }//cout<<'\n';
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= j; k++){  
                // remove k, so no of ways is  
                dp[i][j-k]+=mul(dp[i-1][j],dp2[m][k]);
                if(dp[i][j-k]>=mod)dp[i][j-k]-=mod;
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<'\n';
    }
    cout<<dp[n][0] ;
    return 0;
}
