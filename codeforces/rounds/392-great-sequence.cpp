/*
 * Great Sequence  [1642C]
 * Problem:  https://codeforces.com/problemset/problem/1642/C
 * Verdict:  ACCEPTED        Solved: 2022-02-23
 * Language: C++20 (GCC 11-64)
 * Runtime:  296 ms     Memory: 26700 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1642/submission/147481587
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
void moo(string fileName){
    freopen(((fileName)+string(".out")).c_str(),"w",stdout);
    freopen(((fileName)+string(".in")).c_str(),"r",stdin);
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
tc{
    ll n,x;
    cin>>n>>x;
    map<ll,ll>freq{};
    ll a[n];
    for(auto&i:a)cin>>i,++freq[i];
    sort(a,a+n);
    for(int i = 0; i < n; i++){
        ll& f1=freq[a[i]];
        ll& f2=freq[a[i]*x];
        //cout<<a[i]<<' '<<f1<<' '<<f2<<'\n';
        ll mn = min(f1,f2);
        f1-=mn;
        f2-=mn;
    }
    ll ans=0;
    for(auto&it:freq){
        ans+=it.second;
    }  
    cout<<ans<<'\n';
}
}


