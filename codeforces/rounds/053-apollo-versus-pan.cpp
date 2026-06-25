/*
 * Apollo versus Pan  [1466E]
 * Problem:  https://codeforces.com/problemset/problem/1466/E
 * Verdict:  ACCEPTED        Solved: 2022-09-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  1513 ms     Memory: 0 KB
 * Tags:     bitmasks, brute force, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1466/submission/172085602
 */

/// isA AC
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
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()  
ll mod = 1e9 + 7;
int f[60][60];
ll calc(int i, int j, ll n){
    __int128 ans = 0;
    ans = __int128(__int128(1ll<<i)*__int128(1ll<<j))%mod;
    ans*=f[i][i];
    ans%=mod;
    ans*=(f[i][i]-f[min(i,j)][max(i,j)]);
    ans%=mod;
    ans*=f[j][j];
    ans%=mod;
    __int128 ans2 = 0;
    ans2=__int128(__int128(1ll<<i)*__int128(1ll<<j));
    ans2%=mod;
    ans2*=f[i][i];
    ans2%=mod;
    ans2*=f[min(i,j)][max(i,j)];
    ans2%=mod;
    ans2*=n;
    ans2%=mod;
    return (ans+ans2)%mod;
}
int main()
{
    ACPLS("");   
tc{
    for(uint8_t i = 0; i < 60; i++){
        for(uint8_t j = 0; j < 60; j++){
            f[i][j]=0;
        }
    }
    int n;
    ll v;
    cin>>n; 
    int sz = n;
    while(n--){
        cin>>v;
        for(uint8_t i = 0; i < 60; i++){
            for(uint8_t j = i; j < 60; j++){
                f[i][j]+=(v&(1ll<<i))&&(v&(1ll<<j));
            }
        }
    }
    ll ans=0;
    for(uint8_t i = 0; i < 60; i++){
        for(uint8_t j = 0; j < 60; j++){
            ans+=calc(i,j,sz);
            ans%=mod;
        }
    }
    cout<<ans<<'\n';
}
}   