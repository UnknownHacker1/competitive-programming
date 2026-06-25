/*
 * ECOO '19 R3 P1 - Chords  [ecoo19r3p1]
 * Problem:  https://dmoj.ca/problem/ecoo19r3p1
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2024-07-11
 * Language: C++20
 * Runtime:  2.615131437 s     Memory: 7632.0 KB
 * Source:   https://dmoj.ca/src/6487204
 */

#include <bits/stdc++.h> 
using namespace std;  
using ll = long long;
const int N = 1e6 + 3;
int freq[N];
int main()
{
    int n;
    while(cin>>n){ 
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            freq[x]++;
        }
        ll ans = 0;
        for(int i = 1; i < N; i++){
            int totFreq = 0;
            for(int j = 2 * i; j < N; j += i){
                totFreq += freq[j];
            }
            ans += freq[i] * totFreq;
        }
        cout<<ans<<'\n';
        memset(freq,0,sizeof(freq));
    }
    return 0;  
}