/*
 * The Golden Age  [813B]
 * Problem:  https://codeforces.com/problemset/problem/813/B
 * Verdict:  ACCEPTED        Solved: 2021-11-24
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 100 KB
 * Tags:     brute force, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/813/submission/136746405
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
ll f(ll x, ll r){
    ll cur=r,ret=0;
    while(cur>=x){
        cur/=x;
        ++ret;
    }
    return ret;
}
int main()
{
    ACPLS(); 
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    vector<ll>vx,vy;
    vx.push_back(1),vy.push_back(1);
    int cntx=f(x,r),cnty=f(y,r);
    for(ll i = 0, cur = x; i < cntx; i++,cur*=x){
        vx.push_back(cur);
    }
    for(ll i = 0, cur = y; i < cnty; i++,cur*=y){
        vy.push_back(cur);
    }
    vector<ll>res;
    for(int i = 0; i < (int)vx.size(); i++){
        for(int j = 0; j < (int)vy.size(); j++){
            if(vx[i]+vy[j]>=l&&vx[i]+vy[j]<=r)
                res.push_back(vx[i]+vy[j]);
        }
    }
    if(res.empty()){
        cout<<r-l+1;
        return 0;
    }
    sort(all(res)); 
    ll ans=res[0]-l;
    for(int i = 1; i < (int)res.size(); i++){
        ans=max(ans,res[i]-res[i-1]-1);
    }
    ans=max(ans,r-res.back());
    cout<<ans;
}
