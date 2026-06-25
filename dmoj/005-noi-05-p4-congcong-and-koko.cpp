/*
 * NOI '05 P4 - CongCong and KoKo  [noi05p4]
 * Problem:  https://dmoj.ca/problem/noi05p4
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-11-10
 * Language: C++20
 * Runtime:  0.127580604 s     Memory: 15312.0 KB
 * Source:   https://dmoj.ca/src/5020835
 */

/*
ID: BidoTeima
LANG: C++11
TASK: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
        #ifndef ONLINE_JUDGE
            freopen("output.txt", "w", stdout);
            freopen("input.txt", "r", stdin);
        #endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/
vector<int>adj[1005];
int dist[1005][1005];
double dp[1005][1005];
double dfs(int c, int m){
    if(dp[c][m]>=0)
        return dp[c][m];
    if(m == c)
        return 0;
    int c_old_val=c;
    int mn = adj[c][0];
    for(int child : adj[c]){
        if(dist[child][m] < dist[mn][m]){
            mn = child;
        } 
        if(dist[child][m] == dist[mn][m]){
            mn = min(mn, child);
        }
    }
    c = mn;
    if(c == m){
        return dp[c_old_val][m]=1;
    }
    mn = adj[c][0];
    for(int child : adj[c]){
        if(dist[child][m] < dist[mn][m]){
            mn = child;
        } 
        if(dist[child][m] == dist[mn][m]){
            mn = min(mn, child);
        }
    }
    c = mn;
    if(c == m){
        return dp[c_old_val][m]=1;
    }
    double ret = dfs(c, m);
    for(int child : adj[m]){
        ret += dfs(c, child);
    }
    return dp[c_old_val][m] = 1+ret / double(adj[m].size() + 1);
}
int main()
{
    ACPLS("");  
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            dp[i][j]=-1;
        }
    }
    int n,e;
    cin>>n>>e;
    int c,m;
    cin>>c>>m;
    for(int i = 0; i < e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        queue<pair<int,int>>q;
        q.push({i,0});
        bool visited[n+1];
        for(int j = 1; j <= n; j++)visited[j]=0;
        while(q.size()){
            int u = q.front().first;
            int d = q.front().second;
            q.pop();
            if(visited[u])
                continue;
            visited[u]=1;
            dist[i][u] = d;
            for(int v : adj[u]){
                q.push({v,d+1});
            }
        }
    }
    cout<<fixed<<setprecision(3)<<dfs(c,m);
}