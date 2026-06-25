/*
 * Half of Same  [1593D2]
 * Problem:  https://codeforces.com/problemset/problem/1593/D2
 * Verdict:  ACCEPTED        Solved: 2021-10-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 8300 KB
 * Tags:     brute force, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1593/submission/131814553
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
int n;
ll a[45];
map<vector<int>,int>mp{};
map<vector<int>,bool>vis{};
int rec(int idx, int prv, int curg, int rem){
    if(rem==0)
        return curg;
    if(idx==n)
        return 1;
    auto&v=vis[{idx,prv,curg,rem}];
    auto&m=mp[{idx,prv,curg,rem}];
    if(v)
        return m;
    v=1;
    int op1=rec(idx+1,idx,(prv==-1?0:gcd(curg,a[idx]-a[prv])),rem-1);
    int op2=rec(idx+1,prv,curg,rem);
    if(op1==0||op2==0){
        return 0;
    }
    return m = max(op1,op2);
}
int main()
{
    ACPLS();
tc{
    mp.clear();
    vis.clear();
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=rec(0,-1,0,n/2);
    cout<<(ans==0?-1:ans)<<'\n';
}
}