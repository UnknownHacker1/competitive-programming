/*
 * Work Group  [533B]
 * Problem:  https://codeforces.com/problemset/problem/533/B
 * Verdict:  ACCEPTED        Solved: 2024-11-14
 * Language: C++20 (GCC 13-64)
 * Runtime:  249 ms     Memory: 36800 KB
 * Tags:     dfs and similar, dp, graphs, strings, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/533/submission/291505554
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
vector<int>adj[N];
ll dp[N][2];
int a[N];
ll rec(int node, bool b){
    if(dp[node][b] != -1)
        return dp[node][b];
    if(adj[node].empty()){
        if(b == 0) return 0;
        return a[node];
    }
    vector<ll>arr;
    ll tot = 0;
    for(int child : adj[node]){ 
        tot += rec(child, 0);
        arr.push_back(rec(child, 1) - rec(child, 0));
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    ll bestEven = 0, bestOdd = 0;
    for(int i = 1; i < (int)arr.size(); i += 2){
        if(arr[i - 1] + arr[i] <= 0) break;
        bestEven += arr[i - 1] + arr[i];
    } 
    bestOdd = arr[0];
    for(int i = 2; i < (int)arr.size(); i += 2){
        if(arr[i - 1] + arr[i] <= 0) break;
        bestOdd += arr[i - 1] + arr[i];
    }
    if(b == 0) return dp[node][b] = tot + bestEven;
    return dp[node][b] = max(tot + bestOdd, a[node] + tot + bestEven);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int par;
        cin>>par>>a[i];
        --par;
        if(par>=0) adj[par].push_back(i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, rec(i, 1));
    cout<<ans;
    return 0;
}