/*
 * Bus Number  [991E]
 * Problem:  https://codeforces.com/problemset/problem/991/E
 * Verdict:  ACCEPTED        Solved: 2022-08-27
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, combinatorics, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/991/submission/169803949
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
vector<int>freq(10);
map<vector<int>,bool>vis{};
ll fac[20];
ll rec(vector<int>f){
    auto&ref=vis[f];
    if(ref)return 0;
    ref = 1;
    ll ret = 0;
    ll zero = 1;
    for(int i = 0; i < 10; i++){
        if(f[i] < freq[i]){
            f[i]++;
            ret+=rec(f);
            f[i]--;
        }
        if(f[i] == 0 && freq[i] != 0)zero = 0;
    }
    ll num = fac[accumulate(all(f),0)];
    ll den = 1;
    for(int i = 0; i < 10; i++){
        den *= fac[f[i]];
    }
    return ret + zero * (num / den);
}
int main()
{
    ACPLS();
    fac[0]=1;
    for(int i = 1; i <= 19; i++){
        fac[i]=i*fac[i-1];
    }
    ll n;
    cin>>n;
    while(n){
        freq[n%10]++;
        n/=10;
    }
    ll ans = 0;
    for(ll f0 = !!freq[0]; f0 <= freq[0]; f0++){
    for(ll f1 = !!freq[1]; f1 <= freq[1]; f1++){
    for(ll f2 = !!freq[2]; f2 <= freq[2]; f2++){
    for(ll f3 = !!freq[3]; f3 <= freq[3]; f3++){
    for(ll f4 = !!freq[4]; f4 <= freq[4]; f4++){
    for(ll f5 = !!freq[5]; f5 <= freq[5]; f5++){
    for(ll f6 = !!freq[6]; f6 <= freq[6]; f6++){
    for(ll f7 = !!freq[7]; f7 <= freq[7]; f7++){
    for(ll f8 = !!freq[8]; f8 <= freq[8]; f8++){
    for(ll f9 = !!freq[9]; f9 <= freq[9]; f9++){
        ans += fac[f0+f1+f2+f3+f4+f5+f6+f7+f8+f9]
        / (fac[f0] * fac[f1] * fac[f2] * fac[f3] *
           fac[f4] * fac[f5] * fac[f6] * fac[f7] *
           fac[f8] * fac[f9]);
        if(f0){
            ans -= fac[f0+f1+f2+f3+f4+f5+f6+f7+f8+f9-1]
        / (fac[f0-1] * fac[f1] * fac[f2] * fac[f3] *
           fac[f4] * fac[f5] * fac[f6] * fac[f7] *
           fac[f8] * fac[f9]);
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    cout<<ans;
}   