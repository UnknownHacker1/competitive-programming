/*
 * XOR on Segment  [242E]
 * Problem:  https://codeforces.com/problemset/problem/242/E
 * Verdict:  ACCEPTED        Solved: 2025-03-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  592 ms     Memory: 37400 KB
 * Tags:     bitmasks, data structures
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/242/submission/309371622
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
const int N = 1e5 + 3;

int st[N << 2][20], lazy[N << 2], a[N];
void propagate(int node, int l, int r){
    int mid = (l + r) >> 1;
    if(l <= mid && mid + 1 <= r && lazy[node]){
        int x = lazy[node];
        lazy[node] = 0;
        lazy[2 * node + 1] ^= x;
        lazy[2 * node + 2] ^= x;
        for(int i = 0; i < 20; i++){
            if(x & (1 << i)){ 
                st[2 * node + 1][i] = (mid - l + 1) - st[2 * node + 1][i];
                st[2 * node + 2][i] = (r - mid) - st[2 * node + 2][i];
            }
        } 
    }
}
void build(int l, int r, int node){
    if(l > r) return;
    if(l == r){
        for(int i = 0; i < 20; i++){
            st[node][i] = !!(a[l] & (1 << i));
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2 * node + 1);
    build(mid + 1, r, 2 * node + 2);
    for(int i = 0; i < 20; i++){
        st[node][i] = st[2 * node + 1][i] + st[2 * node + 2][i];
    }
}
void update(int ql, int qr, int x, int l, int r, int node){
    if(r < ql || l > qr) return;
    propagate(node, l, r);
    if(ql <= l && r <= qr){
        lazy[node] ^= x;
        for(int i = 0; i < 20; i++){
            if(x & (1 << i)) st[node][i] = (r - l + 1) - st[node][i];
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(ql, qr, x, l, mid, 2 * node + 1);
    update(ql, qr, x, mid + 1, r, 2 * node + 2);
    for(int i = 0; i < 20; i++){
        st[node][i] = st[2 * node + 1][i] + st[2 * node + 2][i];
    }
}
ll query(int ql, int qr, int l, int r, int node){
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr){
        ll ret = 0;
        for(int i = 0; i < 20; i++){
            ret += (1ll << i) * st[node][i];
        }
        return ret;
    }
    int mid = (l + r) >> 1;
    propagate(node,l,r);
    return query(ql, qr, l, mid, 2 * node + 1) + query(ql, qr, mid + 1, r, 2 * node + 2);
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0,n-1,0);
    int m;
    cin>>m;
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            --l,--r;
            cout<<query(l,r,0,n-1,0)<<'\n';
        }else{
            int l,r,x;
            cin>>l>>r>>x;
            --l,--r;
            update(l,r,x,0,n-1,0);
        }
    }
    return 0;
}
