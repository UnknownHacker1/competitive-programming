/*
 * Shrinking Array  [2112B]
 * Problem:  https://codeforces.com/problemset/problem/2112/B
 * Verdict:  ACCEPTED        Solved: 2025-08-31
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  608 ms     Memory: 0 KB
 * Tags:     brute force, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2112/submission/336324619
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
        int a[n];
        for(auto&i:a)cin>>i;
        int ans = -1;
        for(int i = 0; i < n; i++){ 
            int l=-1,g=-1;
            for(int j = 0; j < i; j++){
                if(a[j] < a[i])l=max(l,j);
                if(a[j] > a[i])g=max(g,j);
            }
            if(l != -1 && g != -1){
                if(ans == -1) ans = i - min(l,g) - 1;
                else ans = min(ans, i - min(l,g) - 1);
            }
            for(int j = i + 1; j < n; j++){
                if(abs(a[i]-a[j]) <= 1){
                    if(ans == -1) ans = j - i - 1;
                    else ans = min(ans, j - i - 1);
                }
            }
        } 
        reverse(a,a+n);
        for(int i = 0; i < n; i++){ 
            int l=-1,g=-1;
            for(int j = 0; j < i; j++){
                if(a[j] < a[i])l=max(l,j);
                if(a[j] > a[i])g=max(g,j);
            }
            if(l != -1 && g != -1){
                if(ans == -1) ans = i - min(l,g) - 1;
                else ans = min(ans, i - min(l,g) - 1);
            }
            for(int j = i + 1; j < n; j++){
                if(abs(a[i]-a[j]) <= 1){
                    if(ans == -1) ans = j - i - 1;
                    else ans = min(ans, j - i - 1);
                }
            }
        } 
        cout<<ans<<'\n';
    }
    return 0;
}