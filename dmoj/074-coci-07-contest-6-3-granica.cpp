/*
 * COCI '07 Contest 6 #3 Granica  [coci07c6p3]
 * Problem:  https://dmoj.ca/problem/coci07c6p3
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-06-23
 * Language: C++20
 * Runtime:  0.032527827 s     Memory: 3420.0 KB
 * Source:   https://dmoj.ca/src/5604969
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a,a+n);
    int g = 0;
    for(int i = 1; i < n; i++)g=__gcd(g, a[i] - a[i - 1]);
    for(int i = 2; i * i <= g; i++){
        if(g % i == 0){
            cout<<i<<' ';
            if(i * i != g)
                cout<<g/i<<' ';
        }
    }
    cout<<g<<'\n';
    return 0;
}