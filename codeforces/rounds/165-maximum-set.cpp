/*
 * Maximum Set  [1796C]
 * Problem:  https://codeforces.com/problemset/problem/1796/C
 * Verdict:  ACCEPTED        Solved: 2023-03-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  218 ms     Memory: 0 KB
 * Tags:     binary search, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1796/submission/196272311
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
    if(str.size() && str != "IIOT")
        moo(str);
    else if(str != "IIOT"){
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
#define tcccc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/
ll mod = 998244353;
ll POW(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1){
            ret = (ret * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
ll modinv(ll a){
    a%=mod;
    return POW(a, mod - 2);
}
int main()
{ 
    ACPLS("");
    ll fact[105];
    fact[0] = 1;
    for(int i = 1; i <= 100; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
tcccc{
    int l, r;
    cin>>l>>r;
    int set_size = 1;
    int start = l;
    while(start * 2 <= r){
        set_size++;
        start *= 2;
    }
    cout<<set_size<<" ";
    set_size--;
    ll ans = 0;
    for(int i = 0; i <= set_size; i++){
        ll c = (1 << i);
        for(int j = 1; j + i <= set_size; j++){
            c *= 3;
        }
        // l <= x
        // x * c <= r
        // x <= r / c
        // r / c - l + 1
        //cout<<c<<'.'<<r/c-l+1<<'\n';
        //cout<<c<<"\n";
        ll count = (fact[set_size]%mod * modinv(fact[i] * fact[set_size - i])%mod * (r / c - l + 1)%mod)%mod;
        ans += max(count, 0ll);
        ans %= mod;
    }
    cout<<ans<<'\n';
}
}