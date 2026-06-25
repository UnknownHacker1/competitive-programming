/*
 * IOI '04 P4 - Phidias  [ioi04p4]
 * Problem:  https://dmoj.ca/problem/ioi04p4
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-09-06
 * Language: C++20
 * Runtime:  4.341044114 s     Memory: 5272.0 KB
 * Source:   https://dmoj.ca/src/5754579
 */

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int W,H,n;
int w[203],h[203];
int dp[605][605];
bool good[605][605];
int rec(int x, int y){
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(good[x][y])
        return 0;
    int ret = x * y;
    for(int i = 1; i < x; i++){
        ret=min(ret,rec(i,y)+rec(x-i,y));
    }
    for(int i = 1; i < y; i++){
        ret=min(ret,rec(x,i)+rec(x,y-i));
    }
    return dp[x][y]=ret;
}
int main()
{           
    memset(dp,-1,sizeof(dp));
    cin>>W>>H>>n;
    for(int i = 0; i < n; i++){
        cin>>w[i]>>h[i];
        good[w[i]][h[i]]=1;
    }
    cout<<rec(W,H);
    return 0;
}