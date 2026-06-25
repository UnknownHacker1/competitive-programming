/*
 * Maximum Subrectangle  [1060C]
 * Problem:  https://codeforces.com/problemset/problem/1060/C
 * Verdict:  ACCEPTED        Solved: 2021-09-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 3700 KB
 * Tags:     binary search, implementation, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1060/submission/128526729
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS(){
#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
#define tc int tttttt;cin>>tttttt;while(tttttt--)
#define sumrange(l,r,arr) (l==0?arr[r]:arr[r]-arr[l-1])
int main(){
    ACPLS();
    int n,m;
    cin>>n>>m;
    ll a[n],b[m],x;
    for(int i = 0; i < n; i++){
    	cin>>a[i];
    	if(i)a[i]+=a[i-1];
    }
    for(int i = 0; i < m; i++){
    	cin>>b[i];
    	if(i)b[i]+=b[i-1];
    }
    cin>>x;
    ll ansa[n],ansb[m];
    for(int i = 0; i < n; i++)
    	ansa[i]=1e18;
    for(int i = 0; i < m; i++)
    	ansb[i]=1e18;
    for(int i = 0; i < n; i++){
    	for(int j = i; j < n; j++){
    		ansa[j-i]=
    		min(ansa[j-i],sumrange(i,j,a));
    	}
    }
    for(int i = 0; i < m; i++){
    	for(int j = i; j < m; j++){
    		ansb[j-i]=
    		min(ansb[j-i],sumrange(i,j,b));
    	}
    }
    int ans=0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(ansa[i]*ansb[j]<=x)
    			ans=max(ans,(i+1)*(j+1));
    	}
    }
    cout<<ans;
}