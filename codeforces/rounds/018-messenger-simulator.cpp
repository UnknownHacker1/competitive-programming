/*
 * Messenger Simulator  [1288E]
 * Problem:  https://codeforces.com/problemset/problem/1288/E
 * Verdict:  ACCEPTED        Solved: 2025-03-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  608 ms     Memory: 22900 KB
 * Tags:     data structures
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1288/submission/310407082
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 3;
int st[N << 2][2];
void update(int i, int x, bool b, int l, int r, int node){
    if(i < l || i > r) return;
    if(l == r){
        st[node][b] = x;
        return;
    }
    int mid = (l + r) >> 1;
    update(i, x, b, l, mid, 2 * node + 1), update(i, x, b, mid + 1, r, 2 * node + 2);
    st[node][b]=st[2*node+1][b]+st[2*node+2][b];
}
int query(int ql, int qr, bool b, int l, int r, int node){
    if(l > qr || r < ql) return 0;
    if(ql <= l && r <= qr){
        return st[node][b];
    }
    int mid = (l + r) >> 1;
    return query(ql, qr, b, l, mid, 2 * node + 1) + query(ql, qr, b, mid + 1, r, 2 * node + 2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    int n,m;
    cin>>n>>m;
    int lst[n+1],ans[n+1],x;
    for(int i = 1; i <= n; i++) lst[i] = -1,ans[i]=i;
    for(int i = 0; i < m; i++){
        cin>>x;
        int val;
        if(lst[x] == -1){  
            val = x+query(x+1,n,0,1,n,0);
            ans[x] = max(ans[x], val);
        }else{
            val = query(lst[x] + 1, i, 1, 0, m - 1, 0) + 1;
            update(lst[x], 0, 1, 0, m - 1, 0);
            ans[x] = max(ans[x], val);
        }
        update(x, 1, 0, 1, n, 0);
        update(i, 1, 1, 0, m - 1, 0);
        lst[x] = i;
    } 
    for(int i = 1; i <= n; i++){
        if(lst[i] == -1) ans[i] = max(ans[i],i+query(i+1,n,0,1,n,0));
        else{
            ans[i]=max(ans[i], query(lst[i] + 1, m - 1, 1, 0, m - 1, 0) + 1);
        }
        cout << (lst[i]==-1?i:1) << ' ' << ans[i] << '\n';
    }
    return 0;
}