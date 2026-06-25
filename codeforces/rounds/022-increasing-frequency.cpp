/*
 * Increasing Frequency  [1082E]
 * Problem:  https://codeforces.com/problemset/problem/1082/E
 * Verdict:  ACCEPTED        Solved: 2021-09-14
 * Language: C++17 (GCC 7-32)
 * Runtime:  187 ms     Memory: 19500 KB
 * Tags:     binary search, dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1082/submission/128844599
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
    int n,c;
    cin>>n>>c;
    int pre[n]={0};
    vector<int>occ[(int)5e5+5];
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        occ[x].push_back(i);
        if(x==c)
            ++pre[i];
        if(i>0)pre[i]+=pre[i-1];
    }
    int ans=max(1,pre[n-1]);
    for(int i = 1; i <= 5e5; i++){
        if(occ[i].empty()||i==c)
            continue; 
        int res=1,cur=1;
        for(int j = 1; j < (int)occ[i].size(); j++){
            cur+=1-sumrange(occ[i][j-1],occ[i][j],pre);
            res=max(res,cur);
            cur=max(cur,1);
        }
        ans=max(ans,res+pre[n-1]);
    }
    cout<<ans;
}