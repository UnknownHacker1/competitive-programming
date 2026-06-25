/*
 * Uncle Bogdan and Country Happiness  [1388C]
 * Problem:  https://codeforces.com/problemset/problem/1388/C
 * Verdict:  ACCEPTED        Solved: 2022-06-16
 * Language: C++20 (GCC 11-64)
 * Runtime:  187 ms     Memory: 8100 KB
 * Tags:     dfs and similar, greedy, math, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1388/submission/160774649
 */

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
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
vector<int>adj[(int)1e5+3];
ll h[(int)1e5+3],p[(int)1e5+3],sub[(int)1e5+3];
ll dfs1(int u, int par){
    sub[u]+=p[u];
    for(int ch:adj[u]){
        if(ch==par)continue;
        sub[u]+=dfs1(ch,u);
    }
    return sub[u];
}
bool dfs(int u, int par){
    ll a = (sub[u]+h[u]);
    if(a&1)return 0;
    a>>=1ll;
    if(a>sub[u]||a<0)return 0;
    bool ret=1;
    ll tot=0;
    for(int ch:adj[u]){
        if(ch==par)continue;
        ret&=dfs(ch,u);
        tot+=(sub[ch]+h[ch])/2;
    }
    ret&=tot<=a;
    return ret;
}
int main()
{
    ACPLS(); 
tc{
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        sub[i]=0;
        adj[i].clear();
    }
    for(int i = 1; i <= n; i++)
        cin>>p[i];
    for(int i = 1; i <= n; i++)
        cin>>h[i];
    for(int i = 1; i < n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1,-1); 
    cout<<(dfs(1,-1)?"YES\n":"NO\n");
}
}