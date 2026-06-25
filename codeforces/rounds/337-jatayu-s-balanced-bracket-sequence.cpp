/*
 * Jatayu's Balanced Bracket Sequence  [1726C]
 * Problem:  https://codeforces.com/problemset/problem/1726/C
 * Verdict:  ACCEPTED        Solved: 2022-09-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  452 ms     Memory: 27200 KB
 * Tags:     data structures, dsu, graphs, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1726/submission/171134574
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
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
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()  
vector<int>adj[(int)2e5+3];
bool vis[(int)2e5+3];
vector<int>seg;
int arr[(int)2e5+4];
int build(int l, int r, int idx){
    if(l>r)
        return 1e9;
    if(l==r)
        return seg[idx]=arr[l];
    int mid = (l+r)/2;
    return seg[idx]=min(build(l,mid,2*idx+1),build(mid+1,r,2*idx+2));
}
int query(int ql, int qr, int l, int r, int idx){
    if(ql<=l&&r<=qr)
        return seg[idx];    
    if(r<ql||l>qr)
        return 1e9;
    int mid = (l+r)/2;
    return min(query(ql,qr,l,mid,2*idx+1),query(ql,qr,mid+1,r,2*idx+2));
}
void dfs(int node){
    if(vis[node])return;
    vis[node]=1;
    for(int child : adj[node])
        dfs(child);
}
int main()
{
    ACPLS("");  
tc{
    int n;
    cin>>n;
    seg.assign(8*n+4,0);
    for(int i = 0; i <= 2*n; i++){
        adj[i].clear();
        vis[i] = 0;
        arr[i] = 0;
    }
    char s[2*n+1];
    for(int i = 0; i < 2*n; i++)cin>>s[i];
    map<int,set<int>>st;
    for(int i = 0; i < 2*n; i++)
    {
        if(s[i]=='(')arr[i]++;
        else arr[i]--; 
    }
    for(int i = 0; i < 2*n; i++){
        arr[i]+=arr[i-1];
        if(s[i] == ')'){
            st[arr[i]].insert(i);
        }
    }
    build(0,2*n-1,0);
    int lim[2*n+1];
    for(int i = 0; i < 2*n; i++)
    {   
        if(s[i]=='('){
            int lo = i+1, hi = 2*n-1, ans = lo;
            while(lo<=hi){
                int m = (lo + hi) >> 1;
                if(query(i,m,0,2*n-1,0) >= arr[i] - 1){
                    ans = m;
                    lo = m + 1;
                }
                else hi = m - 1;
            }
            lim[i] = ans;
            auto mn = st[arr[i] - 1].upper_bound(i);
            auto mx = st[arr[i] - 1].upper_bound(lim[i]);
            mx=prev(mx);
            adj[i].push_back(*mn);
            adj[*mn].push_back(i);
            adj[i].push_back(*mx);
            adj[*mx].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 0; i < 2*n; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<'\n';
}
}   