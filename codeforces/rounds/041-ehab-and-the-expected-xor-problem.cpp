/*
 * Ehab and the Expected XOR Problem  [1174D]
 * Problem:  https://codeforces.com/problemset/problem/1174/D
 * Verdict:  ACCEPTED        Solved: 2023-12-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 1300 KB
 * Tags:     bitmasks, constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1174/submission/238110324
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std; 
const int N = 1<<18;
bool vis[N];
int main()
{
    int n,x;
    cin>>n>>x; 
    if(n == 1 && x == 1){
        return cout<<0, 0;
    }
    vector<int>v; 
    vis[x] = 1; 
    int p = 0;
    for(int i = 1; i < (1 << n); i++){
        if(!vis[i ^ x] && !vis[i]){ 
            vis[i ^ x] = 1;
            v.push_back(i ^ p);
            p = i;
        }
    }
    cout<<(int)v.size()<<'\n';
    for(int i : v)cout<<i<<' ';
    return 0;
}