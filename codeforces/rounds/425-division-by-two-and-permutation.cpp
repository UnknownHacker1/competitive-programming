/*
 * Division by Two and Permutation  [1624C]
 * Problem:  https://codeforces.com/problemset/problem/1624/C
 * Verdict:  ACCEPTED        Solved: 2022-02-07
 * Language: C++20 (GCC 11-64)
 * Runtime:  499 ms     Memory: 0 KB
 * Tags:     constructive algorithms, flows, graph matchings, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1624/submission/145566881
 */

/// isA AC
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int main()
{
    ACPLS();
tc{
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    bool vis[n]={0};
    bool sad=0;
    for(int i = n; i >= 1; i--){
        int mn=1e9+1,mnidx=-1;
        for(int j = 0; j < n; j++){
            if(vis[j])continue;
            int x = a[j];
            while(x){
                if(x==i){
                    if(a[j]<mn){
                        mn=a[j];
                        mnidx=j;
                        break;
                    }
                }
                x/=2;
            }
        }
        if(mnidx==-1){
            sad=1;
            break;
        }else vis[mnidx]=1;
    }
    if(!sad)
        cout<<"YES\n";
    else cout<<"NO\n";
}
}


