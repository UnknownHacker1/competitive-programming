/*
 * Security Badge  [101652T]
 * Problem:  Gym/ICPC contest 101652 - problem T
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  1265 ms     Memory: 65300 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/101652/submission/345452329
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    
const int N = 1005;
const int M = 10005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    
    int n,ec,k;
    cin>>n>>ec>>k;

    int s,t;
    cin>>s>>t;

    map<int,int>mp;
    map<int,int>de_mp;
    array<int,4>edges[ec];
    for(int i = 0; i < ec; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        mp[c]=c;
        mp[d]=d;
        edges[i] = {a,b,c,d};
    }
    int idx=0;
    for(auto&it:mp){
        it.second=idx;
        de_mp[idx] = it.first;
        ++idx;
    }
    vector<array<int,3>>adj[n + 1];

    for(auto& [a, b, c, d] : edges){
        adj[a].push_back({b, mp[c], mp[d]}); 
    }
    
    int m = (int)mp.size();

    int dp[n + 1][m];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = m;
        }
    }

    using ar = array<int, 3>;

    priority_queue<ar, vector<ar>, greater<ar>> pq;

    for(int i = 0; i < m; i++){
        pq.push({0, s, i});
        dp[s][i] = 0;
    }
    
    while(!pq.empty()){
        int minL = pq.top()[0];
        int node = pq.top()[1];
        int R = pq.top()[2]; 
        pq.pop();
        if(minL != dp[node][R]) continue; 
        for(auto& [child, c, d]: adj[node]){
            if(R <= d && max(minL, c) < dp[child][R]){
                dp[child][R] = max(minL, c);
                pq.push({max(minL, c), child, R});
            }
        }
    }
    ll ans = 0; 
    pair<int,int>cur={-1,0};
    for(int i = m - 1; i >= 0; ){
        int val = dp[t][i];
        // cout << val << ' ' << i << '\n';
        if(val > i){
            --i;
            continue;
        } 
        ans += de_mp[i] - de_mp[val] + 1; 
        i = val - 1;
    } 


    cout << ans;

    return 0;
}
