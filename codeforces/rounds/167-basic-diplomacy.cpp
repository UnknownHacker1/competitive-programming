/*
 * Basic Diplomacy  [1482C]
 * Problem:  https://codeforces.com/problemset/problem/1482/C
 * Verdict:  ACCEPTED        Solved: 2021-11-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 5400 KB
 * Tags:     brute force, constructive algorithms, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1482/submission/134530775
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(m);
    int freq[n+1]={0};
    for(int i = 0; i < m; i++){
        int k;
        cin>>k;
        for(int j = 0; j < k; j++){
            int x;
            cin>>x;
            a[i].push_back(x);
            ++freq[x];
        }
    }
    vector<int>ans;
    for(int i = 0; i < m; i++){
        int best = a[i][0],f=freq[a[i][0]];
        for(int j = 0; j < (int)a[i].size(); j++){
            if(freq[a[i][j]]<f){
                f=freq[a[i][j]];
                best=a[i][j];
            }
        }
        ans.push_back(best);
        ++freq[best];
        for(int j = 0; j < (int)a[i].size(); j++){
            --freq[a[i][j]];
        }
    }
    memset(freq,0,sizeof(freq));
    for(int i:ans)++freq[i];
    bool sadness=0;
    for(int i:ans){
        if(freq[i]>(m+1)/2)sadness=1;
    }
    if(sadness){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        for(int i:ans)cout<<i<<' ';
        cout<<'\n';
    }
}
}
