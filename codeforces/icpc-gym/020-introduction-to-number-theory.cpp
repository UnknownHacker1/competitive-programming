/*
 * Introduction to Number Theory  [106251D]
 * Problem:  Gym/ICPC contest 106251 - problem D
 * Verdict:  ACCEPTED        Solved: 2026-06-20
 * Language: C++20 (GCC 13-64)
 * Runtime:  1281 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/106251/submission/379574149
 */

#include <bits/stdc++.h>

using namespace std;

vector<bool> isprime(1e5+2);

void fun(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> div;
    for(int i=1; i*i <=v[n-1]; i++){
        if(v[n-1]%i==0){
            div.push_back(i);
            if(i!= v[n-1]/i){
                div.push_back(v[n-1]/i);
            }
        }
    }
    
    for(int d : div){
        if(d%v[0] !=0) continue;
        for(int i=1; i<n; i++){
            if(v[i]%d!=0 && d%v[i]!=0){
                break;
            }
            if(i==n-1){
                cout << d << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}
int32_t main(){
    
    int t = 1;
    cin >> t;
    while(t--){
        fun();
    }
}