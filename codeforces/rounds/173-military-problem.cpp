/*
 * Military Problem  [1006E]
 * Problem:  https://codeforces.com/problemset/problem/1006/E
 * Verdict:  ACCEPTED        Solved: 2021-10-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  187 ms     Memory: 16800 KB
 * Tags:     dfs and similar, graphs, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1006/submission/133097510
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
vector<int>adj[(int)2e5+3];
vector<int>res;
pair<int,int>rng[(int)2e5+3];
void dfs(int node){
    rng[node].first=res.size();
    res.push_back(node);
    for(int child:adj[node]){
        dfs(child);
    }
    rng[node].second=res.size()-1;
}
int main()
{
    ACPLS();
    int n,q;
    cin>>n>>q;
    for(int i = 2; i <= n; i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        sort(all(adj[i]));
    }
    dfs(1);
    int index[(int)2e5+3];
    for(int i = 0; i < (int)res.size(); i++){
        index[res[i]]=i;
    }
    while(q--){
        int u,k;
        cin>>u>>k;
        int idx=index[u];
        if(idx+k-1>=(int)res.size()||idx+k-1<rng[u].first||idx+k-1>rng[u].second){
            cout<<"-1\n";
            continue;
        }
        cout<<res[idx+k-1]<<'\n';
    }
}
