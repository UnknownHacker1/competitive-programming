/*
 * Shopping Fever  [103149A]
 * Problem:  Gym/ICPC contest 103149 - problem A
 * Verdict:  ACCEPTED        Solved: 2023-12-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 2700 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103149/submission/236908326
 */

#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;   
const int N = 1e5 + 3;
ll dp[N][3];
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);  
    memset(dp,0xf3f3f3f,sizeof(dp));
    int n,q;
    cin>>n>>q;
    q=100-q;
    int p[n];
    for(int i = 0; i < n; i++)cin>>p[i];
    sort(p,p+n);
    if(n == 1){
        cout<<p[0]/100*q;
        return 0;
    }
    dp[1][0] = p[0]/100*q;
    dp[1][1] = 0;
    for(int i = 1; i < n; i++){
        for(int u = 0; u < 3; u++){
            if(u == 0){
                //pop it
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + p[i] / 100ll * q);
                //keep it
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
            }else if(u == 1){
                // pop all 
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (p[i] + p[i - 1]) / 100ll * q);
                // pop first only 
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + p[i - 1] / 100ll * q);
                // pop none
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][1]);
            }else{
                // pop all 
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][2] + p[i] + p[i - 1]);
                // pop first two 
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + (p[i - 1] + p[i - 2]) / 100ll * q);
                // pop first
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + p[i - 2] / 100ll * q);
            }
        }
    }
    cout<<dp[n][0];
    return 0;
}