/*
 * COCI '06 Contest 4 #4 Zbrka  [coci06c4p4]
 * Problem:  https://dmoj.ca/problem/coci06c4p4
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2022-08-31
 * Language: C++20
 * Runtime:  0.466680335 s     Memory: 3544.0 KB
 * Source:   https://dmoj.ca/src/4806401
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename t1>
using ordered_set = tree<t1, null_type,less<t1>, rb_tree_tag,tree_order_statistics_node_update>;
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
    int tttttt,subtask;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
vector<int>dp(10001);
vector<int>pref(10001);
ll mod = 1e9+7;
int main()
{
    ACPLS("");  
    int n,c;
    cin>>n>>c;
    dp[0] = 1;
    pref[0] = 1;
    for(int c = 1; c <= 10000; c++){
        pref[c]+=pref[c-1];
    }
    for(int i = 1; i <= n; i++){
        vector<int>newpref(10001);
        for(int c = 0; c <= 10000; c++){
            dp[c] = 0;
            dp[c] += 1ll*pref[c] - (c - i < 0? 0 : pref[c - i]) + mod;
            dp[c]%=mod;
            newpref[c]=dp[c];
            if(c){
                newpref[c]+=newpref[c-1];
                newpref[c]%=mod;
            }
            /*for(int k = max(0, c - i + 1); k <= c; k++){
                dp[i][c]+=dp[i-1][k];
                dp[i][c]%=mod;
            }*/
        }
        pref=newpref;
    }
    cout<<dp[c];
}