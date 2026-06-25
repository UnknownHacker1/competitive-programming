/*
 * Sorted Pairwise Distance List  [103053A]
 * Problem:  Gym/ICPC contest 103053 - problem A
 * Verdict:  ACCEPTED        Solved: 2023-07-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  826 ms     Memory: 700 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103053/submission/214188126
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = int64_t;

int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    ll x[n],y[n]; 
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
    }
    while(q--){ 
        ll idx,nx,ny;
        cin>>idx>>nx>>ny;
        vector<ll>a,b;
        for(int i = 0; i < n; i++){
            if(i == idx)continue;
            a.push_back((x[i] - nx) * (x[i] - nx) + (y[i] - ny) * (y[i] - ny));
            b.push_back((x[i] - x[idx]) * (x[i] - x[idx]) + (y[i] - y[idx]) * (y[i] - y[idx]));
        }
        sort(a.begin(),a.end()),sort(b.begin(),b.end());
        x[idx]=nx,y[idx]=ny; 
        bool smaller=0,larger=0;
        for(int i = 0; i < (int)a.size(); i++){
            if(a[i] < b[i]){
                smaller = 1;
                break;
            }
            else if(a[i] > b[i]){
                larger = 1;
                break;
            }
        }
        if(smaller){
            cout<<"smaller\n";
        }
        else if(larger){
            cout<<"larger\n";
        }
        else{
            cout<<"equal\n";
        }
    }
    return 0;
}