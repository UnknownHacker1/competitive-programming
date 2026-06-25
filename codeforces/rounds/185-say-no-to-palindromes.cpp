/*
 * Say No to Palindromes  [1555D]
 * Problem:  https://codeforces.com/problemset/problem/1555/D
 * Verdict:  ACCEPTED        Solved: 2021-10-18
 * Language: C++17 (GCC 7-32)
 * Runtime:  156 ms     Memory: 5200 KB
 * Tags:     brute force, constructive algorithms, dp, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1555/submission/132371238
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
int main()
{
    ACPLS();
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int dp[n+5][6]={0};
    string abc="abc";
    int j = 0;
    do{
        for(int i = 0; i < n; i++){
            dp[i+1][j]=dp[i][j]+(s[i]!=abc[i%3]);
        }
        ++j;
    }while(next_permutation(all(abc)));
    while(m--){
        int l,r;
        cin>>l>>r;
        int ans=n;
        for(int j = 0; j < 6; j++){
            ans=min(ans,dp[r][j]-dp[l-1][j]);
        }
        cout<<ans<<'\n';
    }
}