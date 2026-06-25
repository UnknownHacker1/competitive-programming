/*
 * Max GEQ Sum  [1691D]
 * Problem:  https://codeforces.com/problemset/problem/1691/D
 * Verdict:  ACCEPTED        Solved: 2022-08-29
 * Language: C++20 (GCC 11-64)
 * Runtime:  1247 ms     Memory: 61200 KB
 * Tags:     binary search, constructive algorithms, data structures, divide and conquer, implementation, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1691/submission/170078631
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
vector<vector<ll>>seg;
vector<ll>segmn;
vector<vector<ll>>arr;
ll build(int l, int r, int idx, bool b){
    if(l>r)
        return -1e15;
    if(l==r)
        return seg[idx][b]=arr[l][b];
    int mid = (l+r)/2;
    return seg[idx][b]=max(build(l,mid,2*idx+1,b),build(mid+1,r,2*idx+2,b));
}
ll buildmn(int l, int r, int idx){
    if(l>r)
        return 1e15;
    if(l==r)
        return segmn[idx]=arr[l][1];
    int mid = (l+r)/2;
    return segmn[idx]=min(buildmn(l,mid,2*idx+1),buildmn(mid+1,r,2*idx+2));
}
ll query(int ql, int qr, int l, int r, int idx, bool b){
    if(ql<=l&&r<=qr)
        return seg[idx][b];    
    if(r<ql||l>qr)
        return -1e15;
    int mid = (l+r)/2;
    return max(query(ql,qr,l,mid,2*idx+1,b),query(ql,qr,mid+1,r,2*idx+2,b));
}
ll querymn(int ql, int qr, int l, int r, int idx){
    if(ql <= l && r <= qr)
        return segmn[idx];
    if(r < ql || l > qr)
        return 1e15;
    int mid = (l + r)/2;
    return min(querymn(ql,qr,l,mid,2*idx+1),querymn(ql,qr,mid+1,r,2*idx+2));
}
int main()
{
    ACPLS();
tc{
    int n;
    cin>>n;
    seg=vector<vector<ll>>(4*n+4,vector<ll>(2));
    arr=vector<vector<ll>>(n,vector<ll>(2));
    segmn=vector<ll>(4*n+4);
    for(int i = 0; i < n; i++){
        cin>>arr[i][0];
        arr[i][1]=arr[i][0];
        if(i)arr[i][1]+=arr[i-1][1];
        //cout<<arr[i][1]<<' ';
    }
    //cout<<'\n';
    build(0,n-1,0,0);
    build(0,n-1,0,1);
    buildmn(0,n-1,0);
    bool ok = 1;
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        int lo = 0, hi = i;
        while(lo<=hi){
            int m = (lo + hi) >> 1;
            if(query(m,i,0,n-1,0,0) <= arr[i][0]){
                l = m;
                hi = m - 1;
            }
            else lo = m + 1;
        }
        lo = i, hi = n - 1;
        while(lo<=hi){
            int m = (lo + hi) >> 1;
            if(query(i,m,0,n-1,0,0) <= arr[i][0]){
                r = m;
                lo = m + 1;
            }
            else hi = m - 1;
        }
        ll mnleft = 0;
        if(i > l)
            mnleft=arr[i - 1][1] - querymn(max(l-1,0), i-1,0,n-1,0);
        if(l == 0 && i > l)
            mnleft=max(mnleft,arr[i - 1][1]);
        ll mxright = 0;
        if(i < r)
            mxright = query(i + 1, r, 0, n-1, 0, 1) - arr[i][1];
        if(max(mnleft,mxright) > 0){
            ok = 0;
        }
    }
    cout<<(ok?"YES\n":"NO\n");
}
}   