/*
 * Whose Turn Is It?  [105055D]
 * Problem:  Gym/ICPC contest 105055 - problem D
 * Verdict:  ACCEPTED        Solved: 2024-07-23
 * Language: C++20 (GCC 13-64)
 * Runtime:  77 ms     Memory: 100 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/105055/submission/272081211
 */

#include <bits/stdc++.h> 
using namespace std;   

int main()
{  
    int n,m;
    cin>>n>>m;
    if((n / m) & 1) cout << "JOAOZAO";
    else cout << "MARCEL";
    return 0;  
}