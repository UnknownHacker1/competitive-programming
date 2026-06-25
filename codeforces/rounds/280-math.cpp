/*
 * Math  [1062B]
 * Problem:  https://codeforces.com/problemset/problem/1062/B
 * Verdict:  ACCEPTED        Solved: 2022-12-14
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1062/submission/185154451
 */

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int>powerPrime;
    for(int64_t i = 2; i <= n; i++){
        while(n % i == 0){
            powerPrime[i] ++;
            n /= i;
        }
    }
    int ans = 1;
    int mxPower = 0;
    for(auto& i : powerPrime)ans *= i.first,mxPower=max(mxPower,i.second);
    cout<<ans<<' ';
    int closestPowerOf2 = 1, ans2 = 0;
    while(closestPowerOf2 < mxPower)closestPowerOf2*=2, ans2++;
    int b = 0;
    for(auto&i : powerPrime)if(i.second != closestPowerOf2)b = 1;
    cout<<ans2 + b;
    return 0;
}