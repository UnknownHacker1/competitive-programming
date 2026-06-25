/*
 * ATM and Students  [1611F]
 * Problem:  https://codeforces.com/problemset/problem/1611/F
 * Verdict:  ACCEPTED        Solved: 2022-08-30
 * Language: C++20 (GCC 11-64)
 * Runtime:  686 ms     Memory: 7800 KB
 * Tags:     binary search, data structures, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1611/submission/170153908
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename t1>
using ordered_set = tree<t1, null_type,less<t1>, rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
        #ifndef ONLINE_JUDGE
            freopen("output.txt", "w", stdout);
            freopen("input.txt", "r", stdin);
        #endif
    }
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
vector<ll>seg;
vector<ll>arr;
ll build(int l, int r, int idx){
    if(l>r)
        return 1e15;
    if(l==r)
        return seg[idx]=arr[l];
    int mid = (l+r)/2;
    return seg[idx]=min(build(l,mid,2*idx+1),build(mid+1,r,2*idx+2));
}
ll query(int ql, int qr, int l, int r, int idx){
    if(l>r)
        return 1e15;
    if(l > qr || r < ql)
        return 1e15;
    if(ql <= l && r <= qr)
        return seg[idx];
    int mid = (l + r) >> 1;
    return min(query(ql, qr, l, mid, 2*idx+1), query(ql, qr, mid+1, r, 2*idx+2));
}
int main()
{
    ACPLS();
tc{
    int n,s;
    cin>>n>>s;
    seg=vector<ll>(4*n+4);
    arr=vector<ll>(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int lol = n;
    if(arr[0]<-s)lol=0;
    for(int i = 1; i < n; i++){
        arr[i]+=arr[i-1];
        if(arr[i]<-s&&lol==n)lol=i;
    }
    build(0,n-1,0);
    int ans = lol;
    int l = 0, r = lol - 1;
    for(int i = 0; i < n-1; i++){
        int lo = i+1, hi = n-1, res = i;
        while(lo <= hi){
            int m = (lo + hi) >> 1;
            if(query(i+1,m,0,n-1,0) >= arr[i] - s){
                res = m;
                lo = m + 1;
            }
            else hi = m - 1;
        }
        if(res - i > ans){
            ans = res - i;
            l = i+1;
            r = res;
        }
    }
    if(r == -1)
        cout<<"-1\n";
    else
        cout<<l+1<<' '<<r+1<<'\n';
}
}   