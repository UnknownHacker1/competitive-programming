/*
 * M  [106251A]
 * Problem:  Gym/ICPC contest 106251 - problem A
 * Verdict:  ACCEPTED        Solved: 2026-06-20
 * Language: C++20 (GCC 13-64)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/106251/submission/379570835
 */

#include <bits/stdc++.h>

using namespace std;


void fun(){
    int n;
    cin >> n;
    vector<vector<char>> v(n+1, vector<char>(n+1, '.'));
    for(int i=0; i<=n; i++){
        v[i][1] = '#';
        v[i][n] = '#';
    }
    int cnt = 2;
    for(int i=2; i<=n/2; i++){
        v[cnt][i] = '#';
        cnt++;
    }
    cnt = 2;
    for(int i = n-1; i>n/2; i--){
        v[cnt][i] = '#';
        cnt++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << v[i][j];
        }
        cout << '\n';
    }
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        fun();
    }
}