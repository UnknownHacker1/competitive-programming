/*
 * Rising Sand  [1698B]
 * Problem:  https://codeforces.com/problemset/problem/1698/B
 * Verdict:  ACCEPTED        Solved: 2022-06-28
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 800 KB
 * Tags:     constructive algorithms, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1698/submission/162070374
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
tc{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(auto&i:a)cin>>i;
    int ans=0;
    for(int i = 1; i < n-1; i++){
        if(a[i]>a[i-1]+a[i+1])ans++;
    }
    int cnt=0;
    for(int i = 1; i < n-1; i+=2){
        cnt++;
    }
    cout<<(k==1?cnt:ans)<<'\n';
}
}