/*
 * Tree Pruning  [2018C]
 * Problem:  https://codeforces.com/problemset/problem/2018/C
 * Verdict:  ACCEPTED        Solved: 2025-03-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  640 ms     Memory: 28400 KB
 * Tags:     brute force, dfs and similar, greedy, sortings, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2018/submission/309560726
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
const int N = 5e5 + 3;
int n;
vector<int>adj[N];
int dist[N],mx[N]; 
void dfs(int node, int p = -1){ 
    if(p != -1) dist[node] = dist[p] + 1; 
    mx[node] = dist[node];
    for(int child : adj[node]){
        if(child != p){
            dfs(child,node);
            mx[node]=max(mx[node],mx[child]); 
        }
    } 
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){ 
        cin>>n; 
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            dist[i]=0;
            mx[i]=0;
        }
        for(int i = 1; i < n; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        } 
        dfs(1);
        int cost_suff[n]{};//cost_suff[i] -> cost to erase all leaves and traces with distance >= i
        for(int i = 2; i <= n; i++) ++cost_suff[dist[i]],assert(dist[i]);
        for(int i = n - 2; i >= 0; i--) cost_suff[i] += cost_suff[i + 1];
        int cost[n]{}; // cost[i] -> cost to erase all leaves and traces with distance <= i
        for(int i = 2; i <= n; i++) ++cost[mx[i]],assert(mx[i]);
        int ans = n-1;
        /*for(int i = 2; i <= n; i++){
            cout<<"dist to "<<i<<" is "<<dist[i]<<'\n';
        }*/
        for(int i = 1; i < n; i++)cost[i]+=cost[i-1];
        for(int i = 1; i + 1 < n; i++){ 
            assert(cost[i-1]+cost_suff[i+1]<n);
            ans = min(ans, cost[i-1]+cost_suff[i + 1]);
        }
        ans=min(ans,cost[n-2]); // remove < n - 1
        ans=min(ans,cost_suff[1]); // remove > 1
        cout<<ans<<'\n';
    }
    return 0;
}
