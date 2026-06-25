/*
 * Restore Graph  [404C]
 * Problem:  https://codeforces.com/problemset/problem/404/C
 * Verdict:  ACCEPTED        Solved: 2022-08-21
 * Language: C++20 (GCC 11-64)
 * Runtime:  93 ms     Memory: 13000 KB
 * Tags:     dfs and similar, graphs, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/404/submission/169235609
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int main()
{
	ACPLS();
	int n,k;
	cin>>n>>k;
	int d[n+1],c=0;
	vector<int>occ[n+1];
	for(int i = 1; i <= n; i++){
		cin>>d[i];
		if(!d[i]){
			c++;
		}
		occ[d[i]].push_back(i);
	}
	if(c!=1){
		cout<<-1;
		return 0;
	}
	vector<int>adj[n+1];
	for(int i = 0; i + 1 < n; i++){
		if(occ[i].size()==0&&occ[i+1].size()!=0){
			cout<<-1;
			return 0;
		}
		for(int j = 0; j < (int)occ[i+1].size(); j++){
			adj[occ[i][j%int(occ[i].size())]].push_back(occ[i+1][j]);
			adj[occ[i+1][j]].push_back(occ[i][j%int(occ[i].size())]);
		}
	}
	for(int i = 1; i <= n; i++){
		if(adj[i].size()>k){
			cout<<-1;
			return 0;
		}
	}
	set<pair<int,int>>ans;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int)adj[i].size(); j++){
			ans.insert({min(i,adj[i][j]),max(i,adj[i][j])});
		}
	}
	cout<<(int)ans.size()<<'\n';
	for(auto p : ans)
		cout<<p.first<<' '<<p.second<<'\n';
}	
