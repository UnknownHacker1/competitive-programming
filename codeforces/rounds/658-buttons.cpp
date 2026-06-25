/*
 * Buttons  [1858A]
 * Problem:  https://codeforces.com/problemset/problem/1858/A
 * Verdict:  ACCEPTED        Solved: 2023-08-15
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     games, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1858/submission/218926378
 */

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a + (c % 2) > b)
            cout<<"First\n";
        else cout<<"Second\n";
    }
    return 0;
}