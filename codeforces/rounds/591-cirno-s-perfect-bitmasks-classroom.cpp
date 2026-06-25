/*
 * Cirno's Perfect Bitmasks Classroom  [1688A]
 * Problem:  https://codeforces.com/problemset/problem/1688/A
 * Verdict:  ACCEPTED        Solved: 2022-06-03
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     bitmasks, brute force
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1688/submission/159353800
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
    int x;
    cin>>x;
    if(__builtin_popcount(x)==1){
        cout<<x+(x==1?2:1)<<'\n';
    }
    else{
        for(int i = 0; i < 32; i++){
            if(x&(1ll<<i)){
                cout<<(1ll<<i)<<'\n';
                break;
            }
        }
    }
}
}