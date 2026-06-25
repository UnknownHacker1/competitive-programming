/*
 * Multi-Subject Competition  [1082C]
 * Problem:  https://codeforces.com/problemset/problem/1082/C
 * Verdict:  ACCEPTED        Solved: 2021-09-14
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 6400 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1082/submission/128835299
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS(){
#ifndef ONLINE_JUDGE
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc int tttttt;cin>>tttttt;while(tttttt--)
#define sumrange(l,r,arr) (l==0?arr[r]:arr[r]-arr[l-1])
int main(){
    ACPLS(); 
    int n,m;
    cin>>n>>m;
    vector<int>occ[m];
    for(int i = 0; i < n; i++){
        int s,r;
        cin>>s>>r;
        occ[s-1].push_back(r);
    }
    int ans[n]={0};
    for(int i = 0; i < m; i++){
        if(occ[i].empty())
            continue;
        sort(occ[i].begin(), occ[i].end(),greater<int>());
        for(int j = 0; j < (int)occ[i].size(); j++){
            if(j)occ[i][j]+=occ[i][j-1];
            if(occ[i][j]>0)
                ans[j]+=occ[i][j];
        }
    }
    cout<<*max_element(ans,ans+n);
}
