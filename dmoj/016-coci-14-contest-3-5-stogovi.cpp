/*
 * COCI '14 Contest 3 #5 Stogovi  [coci14c3p5]
 * Problem:  https://dmoj.ca/problem/coci14c3p5
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-12-15
 * Language: C++20
 * Runtime:  1.306533519 s     Memory: 33960.0 KB
 * Source:   https://dmoj.ca/src/5123835
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
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
    while (tttttt--)/*end
*/  
const int N = 4e5 + 3;
int sp[20][N];
int lvl[N];
int lca(int u, int v){
    if(lvl[u] < lvl[v]){
        swap(u, v);
    }
    for(int i = 17; i >= 0; i--){
        if(lvl[sp[i][u]] >= lvl[v]){
            u = sp[i][u];
        }
    }
    if(u == v)
        return u;
    for(int i = 17; i >= 0; i--){
        if(sp[i][u] != sp[i][v]){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}
void insert_vertex(int new_vertex, int parent) {
    sp[0][new_vertex] = parent;
    lvl[new_vertex] = lvl[parent] + 1;
    for (int e = 1; e < 18; ++e)
        sp[e][new_vertex] = sp[e-1][sp[e-1][new_vertex]];
}
int main()
{
    ACPLS(); 
    int n;
    cin>>n;
    int f[n + 1]; 
    for(int i = 0; i <= n; i++)f[i] = i; 
    for(int i = 1; i <= n; i++){
        char ch;
        int v;
        cin>>ch>>v;
        v = f[v];
        if(ch == 'a'){
            insert_vertex(i, v);
        }
        else if(ch == 'b'){
            cout<<v<<'\n';
            f[i] = sp[0][v];
        }
        else{
            int w;
            cin>>w;
            f[i] = v;
            cout<<lvl[lca(v, f[w])]<<'\n';
        }
    }
}