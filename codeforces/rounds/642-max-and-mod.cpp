/*
 * Max and Mod  [2084A]
 * Problem:  https://codeforces.com/problemset/problem/2084/A
 * Verdict:  ACCEPTED        Solved: 2025-04-05
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2084/submission/314072921
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
        if(n%2==0)cout<<"-1\n";
        else{
            cout<<n<<' ';
            for(int i = 1; i < n; i++)cout<<i<<' ';
            cout<<'\n';
        }
    }
    return 0;
}