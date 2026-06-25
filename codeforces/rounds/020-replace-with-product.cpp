/*
 * Replace With Product  [1872G]
 * Problem:  https://codeforces.com/problemset/problem/1872/G
 * Verdict:  ACCEPTED        Solved: 2023-12-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  61 ms     Memory: 2900 KB
 * Tags:     brute force, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1872/submission/238430370
 */

#include <bits/stdc++.h> 
using ll = long long;
using namespace std; 
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
        int a[n];
        ll prod = 1;
        bool overflow = 0;
        vector<int>v; 
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(!overflow && prod > 1e18 / a[i]){
                overflow = 1; 
            }
            else if(!overflow) prod *= a[i];
            if(a[i] > 1){
                v.push_back(i);
            }
        } 
        if(overflow){
            cout<<v.front()+1<<' '<<v.back()+1<<'\n';
            continue;
        }
        int bestL = 1, bestR = 1;
        ll diff = 0;
        for(int l = 0; l < (int)v.size(); l++){
            for(int r = l; r < (int)v.size(); r++){
                ll prod = 1, sum = 0;
                for(int i = v[l]; i <= v[r]; i++){
                    prod *= a[i];
                    sum += a[i];
                }
                if(prod - sum > diff){
                    diff = prod - sum;
                    bestL = v[l] + 1;
                    bestR = v[r] + 1;
                }
            }
        }
        cout<<bestL<<' '<<bestR<<'\n';
    }
    return 0;
}