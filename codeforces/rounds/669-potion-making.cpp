/*
 * Potion-making  [1525A]
 * Problem:  https://codeforces.com/problemset/problem/1525/A
 * Verdict:  ACCEPTED        Solved: 2021-05-16
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1525/submission/116392336
 */

#include <bits/stdc++.h>
using namespace std;
//coded this on phone lol
int main()
{
    int tt;
    cin>>tt;
    while(tt--){
    long long n;
    cin>>n;
    cout<<100/gcd(100,n)<<'\n';
    }
    return 0;
}