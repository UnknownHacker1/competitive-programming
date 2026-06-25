/*
 * Palindromic Subsequences  [2056C]
 * Problem:  https://codeforces.com/problemset/problem/2056/C
 * Verdict:  ACCEPTED        Solved: 2025-11-03
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2056/submission/347183920
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
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;
        if(n == 6){
            cout << "1 1 2 3 1 2\n";
            continue;
        }
        for(int i = 1; i <= (n)/2; i++){
            cout << i << ' ';
        }
        if(n & 1) cout << n <<' ';
        
        for(int i = 1; i <= (n)/2; i++){
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}