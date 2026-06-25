/*
 * Berland Music  [1622B]
 * Problem:  https://codeforces.com/problemset/problem/1622/B
 * Verdict:  ACCEPTED        Solved: 2024-04-21
 * Language: C++20 (GCC 13-64)
 * Runtime:  124 ms     Memory: 1800 KB
 * Tags:     data structures, greedy, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1622/submission/257554710
 */

#include <bits/stdc++.h> 
using namespace std;  
using ll = long long;   

int main(){  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0; i < n; i++)cin>>p[i]; 
        vector<pair<int,int>>one,zero;
        for(int i = 0; i < n; i++){
            char ch;
            cin>>ch;
            if(ch=='0'){
                zero.push_back({p[i], i});
            }
            else one.push_back({p[i], i});
        }
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());
        int a[n];
        for(int i = 0; i < (int)zero.size(); i++){
            a[zero[i].second] = i;
        }
        for(int i = 0; i < (int)one.size(); i++){
            a[one[i].second] = i + (int)zero.size();
        }
        for(int i = 0; i < n; i++)cout<<a[i]+1<<' ';
        cout<<'\n';
    }
}