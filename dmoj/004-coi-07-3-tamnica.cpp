/*
 * COI '07 #3 Tamnica  [coi07p3]
 * Problem:  https://dmoj.ca/problem/coi07p3
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-05-18
 * Language: C++20
 * Runtime:  0.669799454 s     Memory: 29696.0 KB
 * Source:   https://dmoj.ca/src/5547178
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <memory.h>
#include <queue>
using namespace std;
using ll = long long;
ll Sqrt(ll x){
    ll lo = 0, hi = 1e8, m, ret;
    while(lo <= hi){
        m = (lo + hi) >> 1;
        if(m * m < x){
            ret = m;
            lo = m + 1;
        }
        else if(m * m > x){
            hi = m - 1;
        }
        else{ret = m;break;}
    }
    return ret; 
}
bool isEdge(ll B){
    ll x = Sqrt(B - 1);
    return x * x == B - 1 || x * (x + 1) == B - 1;
}
int f(ll B){
    if(B == 0)
        return 1;
    ll x = Sqrt(B); 
    if(x * (x + 1) <= B)
        return 2 * (x + 1);
    return 2 * (x + 1) - 1;
}
ll findA(ll B){
    if(isEdge(B))
        return -1;
    if(B == 4){
        return 1;
    } 
    if(B == 6){
        return 1;
    }
    return B - 7 - 2 * (f(B - 1) - f(7));
}
int main()
{         
    ll n;
    int k;
    cin>>n>>k;
    vector<ll> Bs;
    vector<ll> vals;
    vals.push_back(1);
    for(int i = 0; i < k; i++){
        ll B;
        cin>>B;
        ll A = findA(B);
        assert(A != -1);
	Bs.push_back(B);
        vals.push_back(A), vals.push_back(B);
    } 
    vals.push_back(n);
    vector<pair<int,ll>>adj[2 * (k + 1)];
    sort(vals.begin(), vals.end());
    int cur = 0;
    for(int i = 1; i < (int)vals.size(); i++){ 
        if(vals[i] != vals[cur]){
            adj[cur].push_back({i, vals[i] - vals[cur]});
            adj[i].push_back({cur, vals[i] - vals[cur]});
            cur = i;
        } 
    }
    for (ll b: Bs){
	int id_b = lower_bound(vals.begin(), vals.end(), b) - vals.begin(), id_a = lower_bound(vals.begin(), vals.end(), findA(b)) - vals.begin();
	adj[id_b].push_back({id_a, 1});
	adj[id_a].push_back({id_b, 1});
    }
    int n_idx = lower_bound(vals.begin(), vals.end(), n) - vals.begin();
    vals.clear();
    Bs.clear();
    ll dist[2 * (k + 1)];
    for(int i = 0; i < 2 * (k + 1); i++){ 
        dist[i] = 1e15;
    }
    dist[0] = 0;
    using plli = pair<ll, int>;
    priority_queue<plli,vector<plli>,greater<plli>>pq;
    pq.push({0, 0});
    while(!pq.empty()){
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(d != dist[node])
            continue;
        for(auto& edge : adj[node]){
            int child = edge.first;
            ll cost = edge.second;
            if(d + cost < dist[child]){
                dist[child] = d + cost;
                pq.push({dist[child], child});
            }
        }
    }
    cout<<dist[n_idx];
    return 0;
}