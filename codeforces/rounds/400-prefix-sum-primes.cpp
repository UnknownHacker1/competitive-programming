/*
 * Prefix Sum Primes  [1150C]
 * Problem:  https://codeforces.com/problemset/problem/1150/C
 * Verdict:  ACCEPTED        Solved: 2022-07-18
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1150/submission/164820936
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
    int c1=0,c2=0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        c1+=(x==1);
        c2+=(x==2);
    }
    if(c2){
        cout<<"2 ";
        --c2;
    }
    if(c1){
        cout<<"1 ";
        --c1;
    }
    for(int i = 0; i < c2; i++){
        cout<<"2 ";
    }
    for(int i = 0; i < c1; i++){
        cout<<"1 ";
    }
}