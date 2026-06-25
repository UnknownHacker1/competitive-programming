/*
 * Railway  [103149B]
 * Problem:  Gym/ICPC contest 103149 - problem B
 * Verdict:  ACCEPTED        Solved: 2023-12-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  1872 ms     Memory: 800 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103149/submission/236929722
 */

#include <bits/stdc++.h> 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef long long ll;    
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);  
    int s,t,m,n;
    cin>>s>>t>>m>>n;
    int a[t],b[t],c[m],d[n],x;
    for(int i = 0; i < t; i++) cin>>a[i];
    for(int i = 0; i < t; i++) cin>>b[i];
    for(int i = 0; i < m; i++) cin>>c[i];
    for(int i = 0; i < n; i++) cin>>d[i], d[i] += s;
    bool exist = 0;
    for(int i = 0; i < t; i++){
        int j = 0, k = 0;
        // checking if exist there is train L->Z starting while a Z->L train is already inside
        while(j < m && k < n){
            x=d[k]-b[i];
            if(c[j] + a[i] <= x && x < c[j] + b[i]){
                exist = 1;
                break;
            }
            else if(x < c[j] + a[i]){
                ++k;
            }
            else ++j;
        } 
        j = 0, k = 0;
        // same above but swap(Z->L, L->Z)
        while(j < m && k < n){
            x = c[j] + a[i];
            if(d[k] - b[i] <= x && x < d[k] - a[i]){
                exist = 1;
                break;
            }
            else if(x < d[k] - b[i]){
                ++j;
            }
            else ++k;
        } 
        if(exist)break;
    }
    cout<<(exist?"YES":"NO");
    return 0;
}