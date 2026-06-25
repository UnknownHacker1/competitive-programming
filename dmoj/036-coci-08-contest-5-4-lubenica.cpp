/*
 * COCI '08 Contest 5 #4 Lubenica  [coci08c5p4]
 * Problem:  https://dmoj.ca/problem/coci08c5p4
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2023-07-05
 * Language: C++20
 * Runtime:  0.036502196 s     Memory: 5440.0 KB
 * Source:   https://dmoj.ca/src/5622974
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;  
int vis[1<<20]{};
#define int int64_t
int32_t main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int n,h;
    cin>>n>>h;
    vector<int>adj[n]; 
    int cur=0,val=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char ch;
            cin>>ch;
            if(ch=='1'){
                adj[i].push_back(j);
                if(i==0)cur^=1<<j, ++val;
            }
        }
    } 
    vector<int>v;
    vector<ll> p;
    int nxt;
    v.push_back(cur);
    p.push_back(val);
    vis[cur] = 1;  
    while(1){
        nxt=0,val=0;
        for(int i = 0; i < n; i++){
            if(cur&(1<<i)){
                val += int(adj[i].size());
                for(int ch : adj[i]){
                    nxt ^= 1<<ch;
                }
            }else{
                val += 2 * int(adj[i].size());
            }
        } 
        if(vis[nxt]==2)break;
        cur=nxt;  
        ++vis[cur];
        v.push_back(cur);
        p.push_back(val+p.back());
    }
    int mn = min((int)v.size(), h);
    ll ans = p[mn - 1];
    h -= mn;  
    int st;
    for(int i = 0; i < (int)v.size(); i++){ 
        if(v[i] == nxt){
            st = i;
        }
    }  
    int len = (int)v.size() - st;
    ans += h / len * (p.back() - (st == 0? 0 : p[st - 1]));
    h %= len; 
    ans += p[st + h - 1] - (st == 0? 0 : p[st - 1]);
    cout<<ans;
    return 0;
}