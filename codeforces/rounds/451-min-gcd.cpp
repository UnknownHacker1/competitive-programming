/*
 * MIN = GCD  [2084B]
 * Problem:  https://codeforces.com/problemset/problem/2084/B
 * Verdict:  ACCEPTED        Solved: 2025-04-05
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  109 ms     Memory: 100 KB
 * Tags:     greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2084/submission/314095055
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
        ll a[n];
        for(auto&i:a)cin>>i;
        sort(a,a+n);
        reverse(a,a+n);
        bool ok = 0;
        //ll suffmn[n];
        //suffmn[n-1]=a[n-1];
        //for(int i = n - 2; i >= 0; i--)suffmn[i]=min(suffmn[i+1],a[i]);
        ll g = 0;
        for(int i = 0; i + 1 < n; i++){ 
            if(a[i]%a[n-1]==0)g=__gcd(g,a[i]);
        }
        if(g==a[n-1])cout<<"yEs\n";
        else cout<<"nO\n";
    }
    return 0;
}