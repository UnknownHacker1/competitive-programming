/*
 * Tree Cutting (Easy Version)  [1118F1]
 * Problem:  https://codeforces.com/problemset/problem/1118/F1
 * Verdict:  ACCEPTED        Solved: 2022-07-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  296 ms     Memory: 69300 KB
 * Tags:     dfs and similar, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1118/submission/163603816
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
vector<int>adj[(int)3e5+5],adj2[(int)3e5+5];
int sub[(int)3e5+5][2];
int a[(int)3e5+5];
void dfs(int node, int prev){
	sub[node][0]=(a[node]==1);
	sub[node][1]=(a[node]==2);
	for(int ch:adj[node]){
		if(ch==prev)continue;
		adj2[node].push_back(ch);
		dfs(ch,node);
		sub[node][0]+=sub[ch][0];
		sub[node][1]+=sub[ch][1];		
	}
}
int main()
{
	ACPLS();
	int n;
	cin>>n;
	int totr=0,totb=0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i]==1)totr++;
		else if(a[i]==2)totb++;
	}
	for(int i = 1; i < n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	int ans=0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int)adj2[i].size(); j++){
			int r1=sub[adj2[i][j]][0],r2=totr-r1;
			int b1=sub[adj2[i][j]][1],b2=totb-b1;
			if(max(bool(r1)+bool(b1),bool(r2)+bool(b2))<2)
				ans++;
		}	
	}
	cout<<ans;
}
