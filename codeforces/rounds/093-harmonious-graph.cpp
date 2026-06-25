/*
 * Harmonious Graph  [1253D]
 * Problem:  https://codeforces.com/problemset/problem/1253/D
 * Verdict:  ACCEPTED        Solved: 2021-09-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  171 ms     Memory: 17000 KB
 * Tags:     constructive algorithms, dfs and similar, dsu, graphs, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1253/submission/129290332
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
 
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
class dsu{
public:
    dsu(){}
    dsu(int sz){
        parent.resize(sz+1);
        rank.resize(sz+1);
    }
    dsu(const dsu& other){
        this->parent=other.parent;
        this->rank=other.rank;
    }
    void resize(int new_sz){
        parent.resize(new_sz+1);
        rank.resize(new_sz+1);
    }
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v]=find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
private:
    vector<int>parent;
    vector<int>rank;
};
vector<int>adj[(int)2e5+3];
bool vis[(int)2e5+3];
void dfs(int node,vector<int>&cur){
    if(vis[node])
        return;
    vis[node]=1;
    cur.push_back(node);
    for(int child:adj[node])
        dfs(child,cur);
}
dsu G(2e5);
int l=-1,r=-1;
int f(vector<int>&cc){
    int mn=*min_element(all(cc));
    int mx=*max_element(all(cc));
    int ret=0;
    if(l==-1){
        for(int i = mn; i <= mx; i++){
            if(G.find_set(mn)!=G.find_set(i)){
                G.union_sets(mn,i);
                ++ret;
            }
        }
        l=mn;
        r=mx;
    }
    else{
        for(int i = mn; i <= min(l,mx); i++){
            if(G.find_set(mn)!=G.find_set(i)){
                G.union_sets(mn,i);
                ++ret;
            }
        }
        for(int i = max(r+1,mn); i <= mx; i++){
            if(G.find_set(mn)!=G.find_set(i)){
                G.union_sets(mn,i);
                ++ret;
            }
        }
        l=min(l,mn);
        r=max(r,mx);
    }
    return ret;
}
int main()
{
    ACPLS();
    int n,m;
    cin>>n>>m;
    G.resize(n);
    for(int i = 1; i <= n; i++)
        G.make_set(i);
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        G.union_sets(u,v);
    }
    int ans=0;
    vector<vector<int>>v;
    for(int i = 1; i <= n; i++){
        if(adj[i].empty()||vis[i])
            continue;
        vector<int>cur;
        dfs(i,cur);
        sort(all(cur));
        v.push_back(cur);
    }
    sort(all(v), [](const vector<int>&a, const vector<int>&b){
        if(a[0]==b[0])
            return a.back()<b.back();
        return a[0]<b[0];
    });
    for(int i = 0; i < (int)v.size(); i++){
        if(i>0){
            if(v[i][0]>r||v[i].back()<l){
                l=-1,r=-1;
            }
        }
        ans+=f(v[i]);
    }
    cout<<ans;
}