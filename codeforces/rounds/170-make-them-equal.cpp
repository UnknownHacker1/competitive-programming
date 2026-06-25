/*
 * Make Them Equal  [1633D]
 * Problem:  https://codeforces.com/problemset/problem/1633/D
 * Verdict:  ACCEPTED        Solved: 2022-02-04
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 47300 KB
 * Tags:     dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1633/submission/145130981
 */

/// isA AC
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int n,k;
int dp[(int)1e3+5],b[(int)1e3+5],c[(int)1e3+5];
int dp2[(int)1e3+5][12005];
int rec(int idx, int cnt){
    if(idx==n)
        return 0;
    if(dp2[idx][cnt]!=-1)
        return dp2[idx][cnt];
    int ret=0;
    if(cnt>=dp[b[idx]])
        ret=max(ret,rec(idx+1,cnt-dp[b[idx]])+c[idx]);
    ret=max(ret,rec(idx+1,cnt));
    return dp2[idx][cnt]=ret;
}
int main()
{
    ACPLS();
    for(int i = 2; i <= 1e3; i++){
        dp[i]=1e9;
    }
    for(int i = 2; i <= 1e3; i++){
        for(int j = 1; j < i; j++){
            int diff = i-j;
            if(j/diff!=0&&j/(j/diff)==diff)
                dp[i]=min(dp[i],dp[j]+1);
        }
    }
tc{
    cin>>n>>k;
    int s=0;
    for(int i = 0; i < n; i++)
        cin>>b[i],s+=dp[b[i]];
    for(int i = 0; i < n; i++)
        cin>>c[i];
    if(k>s){
        cout<<accumulate(c,c+n,0)<<'\n';
        continue;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp2[i][j]=-1;
        }
    }
    cout<<rec(0,k)<<'\n';
}
}


