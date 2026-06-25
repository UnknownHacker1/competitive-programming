/*
 * NOI '07 P1 - Social Network  [noi07p1]
 * Problem:  https://dmoj.ca/problem/noi07p1
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-12-12
 * Language: C++20
 * Runtime:  0.048452465 s     Memory: 3736.0 KB
 * Source:   https://dmoj.ca/src/5114491
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
int main()
{
    ACPLS();   
    int n,m;
    cin>>n>>m;
    int dist[n + 1][n + 1];
    ll C[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 1e9;
            if(i == j){
                dist[i][j] = 0;
            }
            C[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=dist[b][a]=c;
        C[a][b]=C[b][a]=1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][j] == dist[i][k] + dist[k][j] && k != j && k != i){
                    C[i][j] += C[i][k] * C[k][j];
                }
                else if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    C[i][j] = C[i][k] * C[k][j];
                }
            }
        }
    }
    for(int v = 1; v <= n; v++){
        double ans = 0;
        for(int s = 1; s <= n; s++){
            for(int t = 1; t <= n; t++){
                if(s == t || t == v)
                    continue;
                if(dist[s][v] + dist[v][t] == dist[s][t]){
                    ans += 1.0 * C[s][v] * C[v][t] / C[s][t];
                }
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<'\n';
    }
}