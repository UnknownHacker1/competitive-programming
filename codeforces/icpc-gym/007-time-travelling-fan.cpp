/*
 * Time-travelling Fan  [103053C]
 * Problem:  Gym/ICPC contest 103053 - problem C
 * Verdict:  ACCEPTED        Solved: 2023-07-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  1201 ms     Memory: 133000 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103053/submission/214214039
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = int64_t;
map<string,int>mp{};
map<int,int>idx{};
const int N = 3e5 + 3;
ll st[5][4 * N],lazy[5][4 * N];
void push(int v, int si){
    st[si][2 * v + 1] += lazy[si][v];
    lazy[si][2 * v + 1] += lazy[si][v];
    st[si][2 * v + 2] += lazy[si][v];
    lazy[si][2 * v + 2] += lazy[si][v];
    lazy[si][v] = 0;
}
void update(int ql, int qr, int x, int l, int r, int node, int si){
    if(ql > qr)
        return;
    if(l == ql && r == qr){
        st[si][node] += x;
        lazy[si][node] += x;
        return;
    }
    push(node, si);
    int mid = (l + r) >> 1;
    update(ql, min(qr, mid), x, l, mid, 2 * node + 1, si);
    update(max(ql, mid + 1), qr, x, mid + 1, r, 2 * node + 2, si);
    st[si][node] = max(st[si][2 * node + 1], st[si][2 * node + 2]);
}
ll query(int ql, int qr, int l, int r, int node, int si){
    if(r < ql || l > qr){
        return 0;
    }
    if(ql <= l && r <= qr){
        return st[si][node];
    }
    push(node,si);
    int mid = (l + r) >> 1;
    return max(query(ql, qr, l, mid, 2 * node + 1, si), query(ql, qr, mid + 1, r, 2 * node + 2, si));
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    mp["Amelia"]=0;
    mp["Calliope"]=1;
    mp["Gura"]=2;
    mp["Ina"]=3;
    mp["Kiara"]=4;
    int q;
    cin>>q;
    vector<vector<int>>queries;
    while(q--){
        string s;
        int x,t;
        cin>>s>>x>>t;
        idx[t];
        queries.push_back({mp[s], x, t});
    }
    int cur = 0;
    for(auto&it:idx){
        it.second=cur;
        ++cur;
    }
    int indices[5]={0,0,0,0,0};
    for(vector<int>&v:queries){
        v[2] = idx[v[2]];
        ll ans = 0;
        if(v[0]){
            update(v[2], (int)idx.size() - 1, v[1], 0, (int)idx.size() - 1, 0, v[0]);
        }
        else{
            for(int i = 1; i < 5; i++){
                update(v[2], (int)idx.size() - 1, -v[1], 0, (int)idx.size() - 1, 0, i);
            }
        }
        for(int i = 1; i < 5; i++){
            ans = max(ans, query(0, (int)idx.size() - 1, 0, (int)idx.size() - 1, 0, i));
        }
        cout<<ans<<'\n';
    }

    return 0;
}