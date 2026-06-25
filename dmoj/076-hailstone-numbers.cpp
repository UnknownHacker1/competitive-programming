/*
 * Hailstone Numbers  [hailstone]
 * Problem:  https://dmoj.ca/problem/hailstone
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2024-07-11
 * Language: C++20
 * Runtime:  0.173262978 s     Memory: 3596.0 KB
 * Source:   https://dmoj.ca/src/6486620
 */

#include <bits/stdc++.h> 
using namespace std; 

int main()
{ 
    int n;
    cin >> n;
    int ans = 0;
    while(n != 1){
        if(n % 2 == 1) n = 3 * n + 1;
        else n = n >> 1;
        ans++;
    }
    cout << ans;
    return 0;  
}