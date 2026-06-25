/*
 * Balanced Removals (Easier)  [1237C1]
 * Problem:  https://codeforces.com/problemset/problem/1237/C1
 * Verdict:  ACCEPTED        Solved: 2021-11-21
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     constructive algorithms, geometry, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1237/submission/136324253
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
class point{
public:
    point(int x_c,int y_c, int z_c):x(x_c),y(y_c),z(z_c){}
    point():x(0),y(0),z(0){}
    ll dist(const point&other){
        return abs(x-other.x)+abs(y-other.y)+abs(z-other.z);
    }
    int x,y,z;
};
int main()
{
    ACPLS();
    int n;
    cin>>n;
    point a[n+1];
    for(int i = 1; i <= n; i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    bool vis[n+1]={0};
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        ll mn=1e18;
        int idx=-1;
        for(int j = 1; j <= n; j++){
            if(vis[j]||i==j)continue;
            if(a[i].dist(a[j])<mn){
                mn=a[i].dist(a[j]);
                idx=j;
            }
        }
        vis[i]=1;
        vis[idx]=1;
        cout<<i<<' '<<idx<<'\n';
    }
}
