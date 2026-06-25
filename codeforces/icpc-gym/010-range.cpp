/*
 * Range  [104391C]
 * Problem:  Gym/ICPC contest 104391 - problem C
 * Verdict:  ACCEPTED        Solved: 2023-07-11
 * Language: C++20 (GCC 11-64)
 * Runtime:  623 ms     Memory: 31400 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/104391/submission/213281233
 */

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std; 
using ll = int64_t;
const int N = 4e5 + 3;
int st[4 * N];
void update(int i, int x, int l, int r, int node){
    if(i < l || i > r)  
        return;
    if(l == r){
        st[node] = x;
        return;
    }
    int mid = (l + r) >> 1;
    update(i, x, l, mid, 2 * node + 1);
    update(i, x, mid + 1, r, 2 * node + 2);
    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}
int query(int ql, int qr, int l, int r, int node){
    if(l > qr || r < ql){
        return 0;
    }
    if(ql <= l && r <= qr){
        return st[node];
    }
    int mid = (l + r) >> 1;
    return max(query(ql, qr, l, mid, 2 * node + 1), query(ql, qr, mid + 1, r, 2 * node + 2));
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);   
    int n;
    cin>>n; 
    vector<vector<int>> a(n, vector<int>(3));
    int r[n];
    for(int i = 0; i < n; i++){
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i; 
        r[i] = a[i][1];
    } 
    sort(a.begin(), a.end(), [&](vector<int>&f,vector<int>&s){
        return f[0] == s[0] ? f[1] < s[1] : f[0] > s[0];
    }); 
    sort(r, r + n);
    int ans[n]; 
    for(int i = 0; i < n; i++){
        if(i && a[i] == a[i - 1]){
            ans[a[i][2]] = ans[a[i - 1][2]];
        } 
        else{
            int x = lower_bound(r, r + n, a[i][1]) - r;
            ans[a[i][2]] = query(0, x, 0, n - 1, 0) + 1;
            update(x, ans[a[i][2]], 0, n - 1, 0);
        } 
    }
    cout<<*max_element(ans, ans + n)<<'\n';
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}