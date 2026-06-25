/*
 * Boris and His Amazing Haircut  [1779D]
 * Problem:  https://codeforces.com/problemset/problem/1779/D
 * Verdict:  ACCEPTED        Solved: 2023-02-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  311 ms     Memory: 47100 KB
 * Tags:     constructive algorithms, data structures, dp, dsu, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1779/submission/194620569
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size() && str != "IIOT")
        moo(str);
    else if(str != "IIOT"){
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
    while (tttttt--)/*end
*/
constexpr int N = 2e5 + 3;
int sp[20][N]; 
int lg[N];
int b[N];
void build(int n){
    for(int i = 0; i < n; i++){
        sp[0][i] = b[i];
        if(i>=2)lg[i]=lg[i>>1]+1;
    }
    lg[n]=lg[n>>1]+1;
    for(int i = 1; i < 20; i++){
        for(int j = 0; j + (1 << i) <= n; j++){
            sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
        }
    }
}
int query(int l, int r){
    int i = lg[r-l+1];
    return max(sp[i][l],sp[i][r-(1<<i)+1]);
}
int main()
{ 
    ACPLS(""); 
tc{
    int n;
    cin>>n;
    int a[n];
    map<int,vector<int>>occ;
    for(auto&i:a)cin>>i;
    for(int i = 0; i < n; i++){
        cin>>b[i];
        if(b[i]!=a[i])
            occ[b[i]].push_back(i);
    } 
    build(n);
    int m;
    cin>>m;
    int x[m];
    map<int,int>freq{};
    for(auto&i:x)cin>>i,++freq[i];
    sort(x,x+m);
    bool ok = 1; 
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) ok = 0; 
    }
    for(auto iter = occ.begin(); iter != occ.end(); ++iter){
        auto&it=*iter;
        vector<int>&v = it.second;
        assert(v.size());
        int prev = 0, res = 1;
        for(int i = 0; i < (int)v.size(); i++){
            if(query(v[prev],v[i]) > it.first){
                prev = i;
                ++res;
            }
        } 
        if(res > freq[it.first]){
            ok = 0;
        }
    }
    cout<<(ok?"YES\n":"NO\n");
}
}