/*
 * Not Adding  [1627D]
 * Problem:  https://codeforces.com/problemset/problem/1627/D
 * Verdict:  ACCEPTED        Solved: 2022-06-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  218 ms     Memory: 100 KB
 * Tags:     brute force, dp, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1627/submission/161510940
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
    bitset<1000001>vis{};
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        vis[x]=1;
    }
    for(int i = 1; i <= 1e6; i++){
        int g=0;
        for(int j = i; j <= 1e6; j+=i){
            g=__gcd(g,vis[j]*j);
        }
        if(g==i)vis[i]=1;
    }
    cout<<vis.count()-n;
}
