/*
 * Unloaded Die  [101652U]
 * Problem:  Gym/ICPC contest 101652 - problem U
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++20 (GCC 13-64)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345433999
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long double sum = 0;
    vector<long double> v(7);
    for(int i=1; i<=6; i++){
        cin >> v[i];
        sum += i*v[i];
    }
    long double mn = 1e9;
    for(int i=1; i<=6; i++)
    {
        if(v[i] == 0) continue;
        long double diff = abs(((3.5 + i*v[i] - sum)/v[i]) -i);
        mn = min(mn,diff);
        
    }
    cout << fixed << setprecision(3) << mn;


    
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t=1;
    // cin >> t;
    while(t--)
    solve();
    return 0;
}