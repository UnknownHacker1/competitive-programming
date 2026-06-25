/*
 * Thematic Contests  [1077E]
 * Problem:  https://codeforces.com/problemset/problem/1077/E
 * Verdict:  ACCEPTED        Solved: 2022-06-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 2900 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1077/submission/161249282
 */

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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
int main()
{
    ACPLS();  
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    sort(a,a+n);
    int cnt=1;
    vector<int>v;
    for(int i = 1; i < n; i++){
        if(a[i]!=a[i-1]){
            v.push_back(cnt);
            cnt=1;
        }
        else ++cnt;
    }
    v.push_back(cnt);
    sort(v.begin(),v.end());
    int ans=0;
    for(int i = 1; i <= n; i++){
        int cur = i;
        auto it=lower_bound(v.begin(),v.end(),cur);
        int cnt=0;
        while(it!=v.end()){
            cnt+=cur;
            cur*=2;
            it=lower_bound(it+1,v.end(),cur);
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}
