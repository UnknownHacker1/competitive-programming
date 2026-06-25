/*
 * Array Fix  [1948B]
 * Problem:  https://codeforces.com/problemset/problem/1948/B
 * Verdict:  ACCEPTED        Solved: 2025-03-23
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     brute force, dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1948/submission/312062923
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        int a[n];
        for(auto&i:a)cin>>i;
        int lst=a[n-1];
        bool ok = 1;
        for(int i = n - 2; i >= 0; i--){
            if(a[i]>lst){
                if(a[i]<10 || a[i]%10 > lst || a[i]/10 > a[i]%10){
                    ok=0;
                }else lst = a[i]/10;
            } else lst = a[i];
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}