/*
 * DWITE '09 R4 #1 - Social Media Overload  [dwite09c4p1]
 * Problem:  https://dmoj.ca/problem/dwite09c4p1
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2024-07-20
 * Language: C++20
 * Runtime:  0.003574001 s     Memory: 3700.0 KB
 * Source:   https://dmoj.ca/src/6503866
 */

#include <bits/stdc++.h> 
using namespace std;  
using ll = long long;

int main()
{  
    for(int i = 0; i < 5; i++){
        double n;
        cin>>n;
        cout<<int(round((150/n)*60))<<'\n';
    }
    return 0;  
}