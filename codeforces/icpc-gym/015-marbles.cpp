/*
 * Marbles  [106251C]
 * Problem:  Gym/ICPC contest 106251 - problem C
 * Verdict:  ACCEPTED        Solved: 2026-06-20
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  156 ms     Memory: 1000 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/106251/submission/379573531
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 3;

int vis[N], p[N];

void dfs(int node){
    vis[node]++;
    if(vis[p[node]]) vis[p[node]]++;
    else dfs(p[node]);
}

bool vis2[N];
char color[N];
void dfs2(int node, char c){
    // cout << node << c << '\n';
    color[node] = c;
    vis2[node] = 1;
    if(!vis2[p[node]]){
        dfs2(p[node], c == 'G'? 'B' : 'G');
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> p[i],vis[i]=0,vis2[i]=0;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
                // if(vis[i] > 1){
                    color[i] = 'R';
                    vis2[i] = 1;
                    dfs2(p[i], 'G');
                // }
                // cout<<'\n';
            }
            cout<<color[i];
            // assert(color[i]!=color[p[i]]);
        }
        cout<<'\n';
    }
    return 0;
}