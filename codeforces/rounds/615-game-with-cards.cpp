/*
 * Game with Cards  [1681A]
 * Problem:  https://codeforces.com/problemset/problem/1681/A
 * Verdict:  ACCEPTED        Solved: 2025-03-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 100 KB
 * Tags:     games, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1681/submission/311393283
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
bool winner(vector<int>&a,vector<int>&b){
    int mxa = *max_element(a.begin(),a.end()), mxb = *max_element(b.begin(), b.end());
    return mxa < mxb;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto&i:a)cin>>i;
        int m;
        cin>>m;
        vector<int>b(m);
        for(auto&i:b)cin>>i;
        bool g1 = winner(a,b), g2 = winner(b,a);
        cout<<(g1?"Bob\n":"Alice\n")<<(g2?"Alice\n":"Bob\n");
    }
    return 0;
}