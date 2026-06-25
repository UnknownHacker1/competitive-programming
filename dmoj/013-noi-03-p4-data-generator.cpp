/*
 * NOI '03 P4 - Data Generator  [noi03p4]
 * Problem:  https://dmoj.ca/problem/noi03p4
 * Verdict:  ACCEPTED (20.0 pts)   Solved: 2022-11-13
 * Language: C++20
 * Runtime:  0.363265619 s     Memory: 34792.0 KB
 * Source:   https://dmoj.ca/src/5029786
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
bool vis[(int)2e5+3];
vector<pair<int,ll>>adj[(int)2e5+3];
ll dp[(int)2e5+3];
void dfs(int node, int prev, ll curdist){
    dp[node]=curdist;
    for(auto& child : adj[node]){
        if(child.first==prev)continue;
        dfs(child.first,node,curdist+child.second);
    }
}
bool vis2[(int)2e5+3];
int Y,Z;
ll curzdist;
void dfs2(int node, int prev, ll curdist){
    if(curdist>curzdist){
        curzdist=curdist;
        Z=node;
    }
    for(auto& child : adj[node]){
        if(child.first==prev)continue;
        dfs2(child.first,node,curdist+child.second);
    }
}
ll distFromY[(int)2e5+3],distFromZ[(int)2e5+3];
void dfs3(int node, int prev, ll curdist, bool YorZ){
    if(!YorZ)distFromY[node]=curdist;
    else distFromZ[node]=curdist;
    for(auto& child : adj[node]){
        if(child.first==prev)continue;
        dfs3(child.first,node,curdist+child.second,YorZ);
    } 
}
int main()
{
    ACPLS("");   
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    dfs(1,-1,0);
    for(int i = 1; i <= n; i++){
        if(dp[i]>dp[Y]){
            Y=i;
        }
    }
    dfs2(Y,-1,0);
    dfs3(Y,-1,0,0);
    dfs3(Z,-1,0,1);
    ll ans=0;
    for(int X = 1; X <= n; X++){
        ll d1=distFromY[X];
        ll d2=distFromZ[X];
        ans=max(ans,min(d1,d2)+distFromZ[Y]);
    }
    cout<<ans;
}