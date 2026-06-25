/*
 * Game on Permutation  [1860C]
 * Problem:  https://codeforces.com/problemset/problem/1860/C
 * Verdict:  ACCEPTED        Solved: 2025-03-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  312 ms     Memory: 4700 KB
 * Tags:     data structures, dp, games, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1860/submission/309886614
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;   
const int N = 3e5 + 3;
int st[N<<2];
void update(int i, int x, int l, int r, int node){
    if(i < l || i > r) return;
    if(l==r){
        st[node]=x;
        return;
    }
    int mid = (l + r) >> 1;
    update(i,x,l,mid,2*node+1),update(i,x,mid+1,r,2*node+2);
    st[node]=max(st[2*node+1],st[2*node+2]);
}
int query(int ql, int qr, int l, int r, int node){
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr){
        return st[node];
    }
    int mid = (l + r) >> 1;
    return max(query(ql,qr,l,mid,2*node+1),query(ql,qr,mid+1,r,2*node+2));
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int t;
    cin>>t;
    while(t--){  
        int n;
        cin>>n;
        for(int i = 0; i <= ((n+2)<<2); i++)st[i]=0;
        int a[n];
        bool good[n+1]{};
        multiset<int>ms;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i]; 
            int best=query(1,a[i],1,n,0);
            ans+=(best==1);
            update(a[i],best+1,1,n,0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
