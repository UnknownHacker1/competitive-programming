/*
 * IOI '06 P4 - The Valley of Mexico  [ioi06p4]
 * Problem:  https://dmoj.ca/problem/ioi06p4
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-12-11
 * Language: C++20
 * Runtime:  0.357351479 s     Memory: 12424.0 KB
 * Source:   https://dmoj.ca/src/5111208
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
int c;
bool connected[1005][1005];
int dp[1005][1005][2];
bool rec(int cur, int lim, bool b){
    // base cases
    if(b == 1 && (lim + c - 1) % c == cur){
        return 1;
    }
    if(b == 0 && (lim + 1) % c == cur){
        return 1;
    }
    if(dp[cur][lim][b] != -1)
        return dp[cur][lim][b];
    bool ret = 0;
    // transitions 
    if(b){
        // stay with same b and same lim
        if(connected[cur][(cur + 1) % c])
            ret |= rec((cur + 1) % c, lim, b);
        // change b and lim
        if(connected[cur][(lim + c - 1) % c])
            ret |= rec((lim + c - 1) % c, cur, !b);
    }
    else{
        // stay with same b and same lim
        if(connected[cur][(cur + c - 1) % c])
            ret |= rec((cur + c - 1) % c, lim, b);
        // change b and lim
        if(connected[cur][(lim + 1) % c])
            ret |= rec((lim + 1) % c, cur, !b);
    }
    return dp[cur][lim][b]=ret;
}
void build(int cur, int lim, bool b){
    cout<<cur+1<<'\n';
    if(b == 1 && (lim + c - 1) % c == cur){
        return;
    }
    if(b == 0 && (lim + 1) % c == cur){
        return;
    } 
    if(b){
        // stay with same b and same lim
        if(connected[cur][(cur + 1) % c] && rec((cur + 1) % c, lim, b)){
            build((cur + 1) % c, lim, b);
            return;
        }
        // change b and lim
        if(connected[cur][(lim + c - 1) % c] && rec((lim + c - 1) % c, cur, !b)){
            build((lim + c - 1) % c, cur, !b);
            return;
        }
    }
    else{
        // stay with same b and same lim
        if(connected[cur][(cur + c - 1) % c] && rec((cur + c - 1) % c, lim, b)){
            build((cur + c - 1) % c, lim, b);
            return;
        }
        // change b and lim
        if(connected[cur][(lim + 1) % c] && rec((lim + 1) % c, cur, !b)){
            build((lim + 1) % c, cur, !b);
            return;
        }
    }
}
int main()
{
    ACPLS(); 
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>c>>n;
    for(int i = 0; i < n; i++){
        int u,v;
        cin>>u>>v;
        --u,--v;
        connected[u][v] = 1;
        connected[v][u] = 1;
    }
    for(int i = 0; i < c; i++){
        if(rec(i, i, 1)){
            build(i, i, 1);
            return 0;
        }
    }
    cout<<"-1\n";
}