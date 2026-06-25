/*
 * Three Paths on a Tree  [1294F]
 * Problem:  https://codeforces.com/problemset/problem/1294/F
 * Verdict:  ACCEPTED        Solved: 2023-12-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  202 ms     Memory: 22000 KB
 * Tags:     dfs and similar, dp, greedy, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1294/submission/238977905
 */

#include <bits/stdc++.h> 
using ll = long long;
using namespace std; 
const int N = 2e5 + 3;
bool vis[N];
vector<pair<int,int>>adj[N];  
array<int,3> best[N];
array<int,2> farthest[N];
void findFarthest(int node, int prv){
    if(adj[node].size() == 1 && prv != -1){
        farthest[node][0] = node;
        farthest[node][1] = 0;
    }
    for(auto & edge : adj[node]){
        int child = edge.first;
        if(child != prv){
            findFarthest(child, node);
            if(farthest[child][1] + 1 > farthest[node][1]){
                farthest[node][1] = farthest[child][1] + 1;
                farthest[node][0] = farthest[child][0];
            }
        }
    }
}
void dfs(int node, int prv){
    if(adj[node].size() == 1 && prv != -1){
        best[node][0]=best[node][1]=node;
        best[node][2]=0;
        return;
    }  
    int node1=-1,node2=-1,d1=0,d2=0;
    for(auto&edge:adj[node]){
        int child = edge.first;
        if(child != prv){
            if(farthest[child][1] + 1 > d1){
                swap(node1,node2);
                swap(d1,d2);
                node1 = farthest[child][0];
                d1 = farthest[child][1] + 1;
            }else if(farthest[child][1] + 1 > d2){
                node2 = farthest[child][0];
                d2 = farthest[child][1] + 1;
            }
            dfs(child, node); 
            if(best[child][2] + 1 > best[node][2] || best[node][0]==best[node][1]){
                best[node][2] = best[child][2] + 1;
                tie(best[node][0], best[node][1]) = {best[child][0], best[child][1]};
            }
        }
    }
    if(node2 != -1){
        if(d1 + d2 > best[node][2]){
            best[node][0] = node1;
            best[node][1] = node2;
            best[node][2] = d1 + d2;
        }
    }
}
vector<int>ans;
void findBest(int node, int prv){
    if(adj[node].size() == 1 && prv != -1) return;
    //first case: take node which is the lca and its best
    if(node != best[node][0] && best[node][0] != best[node][1] && best[node][2] > ans.front()){ 
        ans={best[node][2],node,best[node][0],best[node][1]};
    }
    for(auto it = adj[node].begin(); it != adj[node].end(); ++it){
        if(it->first == prv){
            adj[node].erase(it);
            break;
        }
    }
    sort(adj[node].begin(),adj[node].end(),[](pair<int,int>&f,pair<int,int>&s){
        return farthest[f.first][1] > farthest[s.first][1];
    });
    // second case, take best unrelated 3 
    if(adj[node].size() >= 3 && farthest[adj[node][0].first][1] + farthest[adj[node][1].first][1] + farthest[adj[node][2].first][1] + 3 
    > ans.front()) {
        ans = {farthest[adj[node][0].first][1] + farthest[adj[node][1].first][1] + farthest[adj[node][2].first][1] + 3, 
        farthest[adj[node][0].first][0], farthest[adj[node][1].first][0], farthest[adj[node][2].first][0]};
    }
    // third case, take best 2 from 1 and best 1 other than this one
    if(adj[node].size()>=2)for(int i = 0; i < (int)adj[node].size(); i++){
        int other = adj[node][i == 0].first;
        int child = adj[node][i].first;
        if(best[child][0] != best[child][1] && best[child][2] + farthest[other][1] + 2 > ans.front() ){
            ans={best[child][2] + farthest[other][1] + 2, best[child][0], best[child][1], farthest[other][0]};
        }
    } 
    for(auto&edge:adj[node]){
        findBest(edge.first,node);
    }
}
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    } 
    findFarthest(1,-1);
    dfs(1,-1);
    ans.push_back(-1);
    findBest(1, -1); 
    //last case; a line
    for(int i = 0; i < (int)adj[1].size(); i++){
        if(farthest[adj[1][i].first][0] == farthest[1][0] && adj[1][i].first != farthest[1][0] && farthest[1][1]>ans.front()){
            ans={farthest[1][1], 1, adj[1][i].first, farthest[1][0]};
        }
    } 
    cout<<ans.front()<<'\n'; 
    for(int i = 1; i <= 3; i++)cout<<ans[i]<<' ';
    return 0;
}