/*
 * Tea Tasting  [1795C]
 * Problem:  https://codeforces.com/problemset/problem/1795/C
 * Verdict:  ACCEPTED        Solved: 2025-03-20
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  171 ms     Memory: 3500 KB
 * Tags:     binary search, data structures, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1795/submission/311530666
 */

 
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  

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
        ll a[n],pre[n],b[n];
        for(auto&i:a)cin>>i;
        for(int i = 0; i < n; i++){
            cin>>b[i];
            pre[i]=b[i];
            if(i)pre[i]+=pre[i-1];
        }
        ll semi[n]{}; // semi drinks (i.e. tot.. + semi[i])
        int full[n+1]{}; // full drinks (i.e. tot.. + b[i] x full[i]) 
        for(int i = 0; i < n; i++){
            // biggest index j such that a[i] >= pre[j] - pre[i - 1] (b[i]+b[i+1]+...+b[j])
            // pre[j] <= a[i] + pre[i - 1]
            int idx = upper_bound(pre + i, pre + n, a[i] + (i==0?0:pre[i-1])) - pre;
            if(idx == i){
                // none exists, just move on with life :(
                semi[i] += a[i]; 
            }else{
                ++full[i];
                --full[idx];
                if(idx < n){
                    ll rem = a[i] - (pre[idx-1] - (i==0?0:pre[i-1]));
                    semi[idx] += rem; 
                }
            }
        }
        for(int i = 1; i < n; i++)full[i]+=full[i-1];
        for(int i = 0; i < n; i++) cout<<b[i]*full[i]+semi[i]<<' ';
        cout<<'\n';
    }
    return 0;
}