/*
 * High Load  [827B]
 * Problem:  https://codeforces.com/problemset/problem/827/B
 * Verdict:  ACCEPTED        Solved: 2022-08-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  78 ms     Memory: 25600 KB
 * Tags:     constructive algorithms, greedy, implementation, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/827/submission/169374233
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
int dest;
vector<int>adj[(int)2e5+3];
int c=1e9;
void dfs(int node = 1, int prev = -1, int cnt = 0){
    if(node==dest){
        c=min(c,cnt);
        return;
    }
    for(int child : adj[node]){
        if(child!=prev){
            dfs(child,node,cnt+1);
        }
    }
}
int main()
{
    ACPLS();    
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>ans;
    for(int i = 1; i < n; i++){
        if(i+k<n){ 
            ans.push_back({i,i+k});
            adj[i].push_back(i+k);
            adj[i+k].push_back(i);
        }
        else{
            ans.push_back({i,n});
            adj[i].push_back(n);
            adj[n].push_back(i);
        }
    }
    dest = 2;
    dfs();
    if(c<n-k+1||c>=n-k+1){
        cout<<c<<'\n';
        for(auto p : ans)cout<<p.first<<' '<<p.second<<'\n';
    }  
    else{
        cout<<n-k+1<<'\n';
        for(int i = 1; i < k; i++){
            cout<<i<<' '<<k<<'\n';
        }
        for(int i = k; i < n; i++){
            cout<<i<<' '<<i+1<<'\n';
        }
    }  
}   