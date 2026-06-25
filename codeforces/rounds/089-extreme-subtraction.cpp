/*
 * Extreme Subtraction  [1442A]
 * Problem:  https://codeforces.com/problemset/problem/1442/A
 * Verdict:  ACCEPTED        Solved: 2023-12-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 200 KB
 * Tags:     constructive algorithms, dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1442/submission/237662309
 */

#include <bits/stdc++.h>   
using namespace std; 
typedef long long ll;     
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
        ll a[n];
        for(int i = 0; i < n; i++)cin>>a[i];
        ll x = 0;
        bool ans = 1;
        for(int i = 1; i < n; i++){
            if(a[i]>a[i-1]){
                x += a[i] - a[i - 1];
            } 
            if(a[i] - x < 0){
                ans = 0;
                break;
            }
        }
        cout<<(ans?"YES\n":"NO\n");
    }
    return 0;
}