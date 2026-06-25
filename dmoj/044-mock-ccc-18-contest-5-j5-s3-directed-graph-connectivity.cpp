/*
 * Mock CCC '18 Contest 5 J5/S3 - Directed Graph Connectivity  [nccc5j5s3]
 * Problem:  https://dmoj.ca/problem/nccc5j5s3
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-08-03
 * Language: C++20
 * Runtime:  1.633330212 s     Memory: 3428.0 KB
 * Source:   https://dmoj.ca/src/4745388
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
vector<int>adj[55];
bool vis[55];
int badu,badv,n;
bool reached;
void dfs(int node){
	if(node==n){
		reached=1;
		return;
	}
	if(vis[node])return;
	vis[node]=1;
	for(int ch:adj[node]){
		if(node!=badu||ch!=badv){
			dfs(ch);
		}
	}
}
int main()
{
	ACPLS();
	int m;
	cin>>n>>m;
	pair<int,int>edges[m];
	for(int i = 0; i < m; i++){
		cin>>edges[i].first>>edges[i].second;
		adj[edges[i].first].push_back(edges[i].second);
	}
	for(int i = 0; i < m; i++){
		badu=edges[i].first,badv=edges[i].second;
		memset(vis,0,sizeof(vis));
		reached=0;
		dfs(1);
		cout<<(reached?"YES\n":"NO\n");
	}
}