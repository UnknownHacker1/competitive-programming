/*
 * NOI '12 P1 - Random Number Generator  [noi12p1]
 * Problem:  https://dmoj.ca/problem/noi12p1
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-04-15
 * Language: C++20
 * Runtime:  0.104464231 s     Memory: 3444.0 KB
 * Source:   https://dmoj.ca/src/5475156
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
ll mod=1e18; 
ll mul(ll a, ll b){
    a %= mod;
    ll res = 0;
    while(b > 0){
        if(b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}
ll binexpo(ll a, ll b){ 
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}
ll calc(ll a, ll n){  
    if(n == 1)
        return 1;
    n>>=1; 
    return mul(calc(a, n), (binexpo(a, n) + 1));
}
int main()
{    
    ACPLS("");   
    ll m,a,c,x0,n,g;
    cin>>m>>a>>c>>x0>>n>>g;
    mod=m;
    ll y = x0;
    for(int i = 0; i < 60; i++){
        if(!(n & (1ll << i)))
            continue;
        y = mul(y, binexpo(a, 1ll<<i)) + mul(calc(a, 1ll<<i), c);
        y %= mod;
    }
    cout << y%g;
    return 0;
}