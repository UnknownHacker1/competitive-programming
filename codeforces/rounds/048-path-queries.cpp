/*
 * Path Queries  [1213G]
 * Problem:  https://codeforces.com/problemset/problem/1213/G
 * Verdict:  ACCEPTED        Solved: 2022-08-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  326 ms     Memory: 8600 KB
 * Tags:     divide and conquer, dsu, graphs, sortings, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1213/submission/169989025
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
int parent[(int)2e5+5];
int sz[(int)2e5+5];
ll ans = 0;
void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void unify(int a, int b){
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b])
        swap(a,b);
    if(a != b){
        ans -= sz[a] * 1ll * (sz[a] - 1) / 2;
        ans -= sz[b] * 1ll * (sz[b] - 1) / 2;
        sz[a] += sz[b];
        ans += sz[a] * 1ll * (sz[a] - 1) / 2;
        parent[b] = a;
    }
}
int main()
{
    ACPLS();
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        make_set(i);
    vector<tuple<int,int,int>>a(n-1);
    for(int i = 0; i < n-1; i++){
        cin>>get<1>(a[i])>>get<2>(a[i])>>get<0>(a[i]);
    }
    pair<int,int> q[m];
    ll res[m]={0};
    for(int i = 0; i < m; i++){
        cin>>q[i].first;
        q[i].second = i;
    }
    sort(q,q+m);
    sort(a.begin(),a.end());
    for(int i = 0; i < n-1; i++){
        unify(get<1>(a[i]),get<2>(a[i]));
        int idx = lower_bound(q,q+m,make_pair(get<0>(a[i]), -1)) - q;
        if(idx < m){
            res[idx] = ans;
        }
    }
    for(int i = 1; i < m; i++){
        res[i]=max(res[i-1],res[i]);
    }
    ll actualres[m];
    for(int i = 0; i < m; i++){
        actualres[q[i].second] = res[i];
    }
    for(int i = 0; i < m; i++){
        cout<<actualres[i]<<' ';
    }
}   