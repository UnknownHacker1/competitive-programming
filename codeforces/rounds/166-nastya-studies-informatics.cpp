/*
 * Nastya Studies Informatics  [992B]
 * Problem:  https://codeforces.com/problemset/problem/992/B
 * Verdict:  ACCEPTED        Solved: 2021-11-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 1200 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/992/submission/134145640
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
ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
int main()
{
    ACPLS();
    ll l,r,x,y;
    cin>>l>>r>>x>>y;
    vector<ll>divx,divy;
    for(ll i = 1; i * i <= x; i++){
        if(x%i==0){
            divx.push_back(i);
            if(i*i!=x)divx.push_back(x/i);
        }
    }
    for(ll i = 1; i * i <= y; i++){
        if(y%i==0){
            divy.push_back(i);
            if(i*i!=y)divy.push_back(y/i);
        }
    }
    ll ans=0;
    map<ll,bool>vis{};
    for(ll i:divx){
        for(ll j:divy){
            ll a=i,b=j,c=i*j;
            if(!vis[a]){
                vis[a]=1;
                if(l<=a&&a<=r&&l<=x*y/a&&x*y/a<=r&&gcd(a,x*y/a)==x&&lcm(a,x*y/a)==y){
                    ++ans;
                }
            }
            if(!vis[b]){
                vis[b]=1;
                if(l<=b&&b<=r&&l<=x*y/b&&x*y/b<=r&&gcd(b,x*y/b)==x&&lcm(b,x*y/b)==y){
                    ++ans;
                }
            }
            if(!vis[c]){
                vis[c]=1;
                if(l<=c&&c<=r&&l<=x*y/c&&x*y/c<=r&&gcd(c,x*y/c)==x&&lcm(c,x*y/c)==y){
                    ++ans;
                }
            }
        }
    }
    cout<<'\n';
    cout<<ans;
}