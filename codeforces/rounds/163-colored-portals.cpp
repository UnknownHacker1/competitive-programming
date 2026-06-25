/*
 * Colored Portals  [2004D]
 * Problem:  https://codeforces.com/problemset/problem/2004/D
 * Verdict:  ACCEPTED        Solved: 2025-03-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  437 ms     Memory: 15900 KB
 * Tags:     binary search, brute force, data structures, graphs, greedy, implementation, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2004/submission/308943276
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;   
map<string,int> id; 
bool intersect[6][6];
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string colors[6] = {"BG", "BR", "BY", "GR", "GY", "RY"};
    for(int i = 0; i < 6; i++){
        id[colors[i]]=i;
    }
    for(int i = 0; i < 6; i++) intersect[i][i]=1;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(colors[i].find(colors[j][0])!=string::npos || colors[i].find(colors[j][1])!=string::npos){
                intersect[i][j]=1;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){ 
        int n,quer;
        cin>>n>>quer; 
        vector<int> v[6];
        int a[n];
        for(int i = 0; i < n; i++){
            string color;
            cin>>color;
            a[i]=id[color];
            v[a[i]].push_back(i);
        }
        vector<int>adj[n];
        for(int i = 0; i < n; i++){
            for(int c = 0; c < 6; c++){ 
                if(v[c].empty())continue;
                if(c == a[i]){
                    if(i != *v[c].begin()) adj[i].push_back(*v[c].begin());
                    if(i != v[c].back()) adj[i].push_back(v[c].back());
                } 
                else if(intersect[a[i]][c]){ 
                    auto it = upper_bound(v[c].begin(),v[c].end(),i);
                    if(it != v[c].end()) adj[i].push_back(*it);
                    if(it != v[c].begin()){
                        it = prev(it);
                        if(*it == i){
                            if(it != v[c].begin()) adj[i].push_back(*prev(it));
                        }
                        else adj[i].push_back(*it);
                    }
                }
            }
        } 
        /*for(auto&vec:adj){
            for(auto&i:vec)cout<<i<<' ';
            cout<<'\n';
        }
        cout<<'\n';*/
        while(quer--){
            int x,y;
            cin>>x>>y;
            --x,--y;
            if(intersect[a[x]][a[y]]){
                cout<<abs(x-y)<<'\n';
                continue;
            }
            queue<array<int,3>>q; 
            int ans = -1;
            q.push({x,0,0});
            while(!q.empty()){
                int node = q.front()[0];
                int dep = q.front()[1];
                int dist = q.front()[2]; 
                q.pop();
                if(intersect[a[node]][a[y]]){
                    ans = (ans == -1 ? dist+abs(node-y) : min(ans, dist+abs(node-y)));
                    continue;
                }  
                if(dep == 4) continue; 
                for(int child : adj[node]){
                    q.push({child, dep + 1, dist + abs(child - node)});;
                }
            }
            cout << ans << '\n';
        }
    }
	return 0;
}
