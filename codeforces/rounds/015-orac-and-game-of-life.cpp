/*
 * Orac and Game of Life  [1349C]
 * Problem:  https://codeforces.com/problemset/problem/1349/C
 * Verdict:  ACCEPTED        Solved: 2025-02-16
 * Language: C++20 (GCC 13-64)
 * Runtime:  218 ms     Memory: 41200 KB
 * Tags:     dfs and similar, graphs, implementation, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1349/submission/306323329
 */

#include <bits/stdc++.h>
using namespace std; 

#define int long long
using ll = long long;

const int N = 1e3 + 5;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
 
int n, m, q;
char w[N][N];
bool vis[N][N];
ll dist[N][N];
ll a, b, c;
queue<pair<int,int>> Q;
 
bool cango(int y, int x){
	return !(y<0||y>=n||x<0||x>=m);
}
 
int32_t main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m >> q; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> w[i][j];
			dist[i][j] = 1e18;
		}
	}
 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<4;k++){
				int ni = i + dy[k];
				int nj = j + dx[k];
				if(cango(ni,nj) && w[ni][nj] == w[i][j]){
					vis[i][j] = true;
					dist[i][j] = 0;
					Q.emplace(i, j);
				}
			}
		}
	}
 
	while(Q.size()){
		pair<int,int> p = Q.front(); Q.pop();
		for(int k=0;k<4;k++){
			int ni = p.first + dy[k];
			int nj = p.second + dx[k];
			if(cango(ni,nj) && !vis[ni][nj]){
				vis[ni][nj] = true;
				dist[ni][nj] = dist[p.first][p.second] + 1;
				Q.emplace(ni, nj);
			}
		}
	}
 
	while(q--){
		cin >> a >> b >> c;
		a--; b--;
		if(c > dist[a][b]){
			cout << char(w[a][b] ^ (abs(c-dist[a][b])%2)) << "\n";
		}
		else{
			cout << w[a][b] << "\n";
		}
	}
 
	return 0;
}
