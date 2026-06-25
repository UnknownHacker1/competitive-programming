/*
 * Skipping  [2024D]
 * Problem:  https://codeforces.com/problemset/problem/2024/D
 * Verdict:  ACCEPTED        Solved: 2025-03-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  390 ms     Memory: 19700 KB
 * Tags:     constructive algorithms, data structures, divide and conquer, dp, flows, graphs, greedy, implementation, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2024/submission/309229885
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(auto&i:a)cin>>i;
        for(auto&i:b)cin>>i,--i;
        vector<pair<int,int>>adj[n];
        for(int i = 0; i < n; i++){
            if(i) adj[i].push_back({i - 1, 0});
            if(b[i] > i) adj[i].push_back({b[i], a[i]});
        }
        ll dist[n];
        dist[0] = 0;
        for(int i = 1; i < n; i++) dist[i] = 1e18;
        using _Ty = pair<ll,int>; 
        priority_queue<_Ty,vector<_Ty>, greater<_Ty>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist[node] != d) continue;
            for(auto& p : adj[node]){
                if(d + p.second < dist[p.first]){
                    dist[p.first] = d + p.second;
                    pq.push({dist[p.first], p.first});
                }
            }
        }
        ll ans = 0, cur = 0;
        for(int i = 0; i < n; i++){
            cur += a[i];
            ans = max(ans, cur - dist[i]);
        }
        cout << ans << '\n';
    }
	return 0;
}
