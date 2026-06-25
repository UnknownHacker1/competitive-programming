/*
 * JOI '20 Open P3 - Power Plant  [joi20op3]
 * Problem:  https://dmoj.ca/problem/joi20op3
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2024-03-30
 * Language: C++20
 * Runtime:  4.487829658 s     Memory: 29072.0 KB
 * Source:   https://dmoj.ca/src/6312909
 */

#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;
const int N = 2e5 + 3;
bool p[N];
vector<int>adj[N];
int dp[N],ans;
void dfs(int node, int prev = -1){ 
    int mx=0;
    for(int child : adj[node]){
        if(child==prev)continue;
        dfs(child,node);
        dp[node] += dp[child];
        mx=max(mx, dp[child]);
    }
    if(p[node]){
        dp[node]=max(dp[node] - 1, 1);
        mx++;
    }
    ans=max(ans,max(dp[node], mx));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        char ch;
        cin>>ch;
        p[i] = ch-'0';
    }
    dfs(1, -1);
    cout<<ans;
    return 0;
}