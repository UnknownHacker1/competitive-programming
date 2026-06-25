/*
 * Shaass the Great  [294E]
 * Problem:  https://codeforces.com/problemset/problem/294/E
 * Verdict:  ACCEPTED        Solved: 2023-08-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  2823 ms     Memory: 900 KB
 * Tags:     dp, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/294/submission/219570898
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
vector<pair<int,int>>adj[N],newAdj[N];
ll subt[N],sumFromRoot=0;
void dfs1(int node, int prev, ll cur){
    sumFromRoot+=cur;
    subt[node] = 1;
    for(auto& edge : newAdj[node]){
        int child = edge.first;
        if(child != prev){
            dfs1(child, node, cur + edge.second);
            subt[node] += subt[child];
        }
    }
}
void calc_size(int root){
    sumFromRoot=0;
    dfs1(root, -1, 0);
}
int root;
ll sumdist[N];
ll best = 1e18;
void dfs2(int node, int prev, ll cur){
    sumdist[node] = cur; 
    best=min(best, cur);
    for(auto& edge : newAdj[node]){
        int child = edge.first;
        ll w = edge.second;
        if(child != prev){
            dfs2(child, node, 
            cur + w * (subt[root] - 2 * subt[child]));
        }
    }
}
void calc_sum_dist(int rt){
    best=1e18;
    root=rt;
    dfs2(root, -1, sumFromRoot);
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    ll ans = 1e18;
    for(int x = 1; x <= n; x++){
        for(auto& edge : adj[x]){
            memset(subt,0,sizeof(subt));
            memset(sumdist,0,sizeof(sumdist));
            int y = edge.first;
            int w = edge.second;
            for(int i = 1; i <= n; i++)newAdj[i]=adj[i];
            newAdj[x].erase(find(newAdj[x].begin(),newAdj[x].end(),make_pair(y,w)));
            newAdj[y].erase(find(newAdj[y].begin(),newAdj[y].end(),make_pair(x,w)));
            ll minSumDistX;
            calc_size(x);
            calc_sum_dist(x);
            minSumDistX=best;
            calc_size(y);
            calc_sum_dist(y);
            ll minSumDistY=best;
            ll sumTotal=0;
            for(int i = 1; i <= n; i++)sumTotal+=sumdist[i];
            ans=min(ans,sumTotal/2 + minSumDistX * subt[y] + minSumDistY * subt[x] + w * subt[x] * subt[y]);
        }
    }
    cout<<ans;
    return 0;
}