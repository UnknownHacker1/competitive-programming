/*
 * Beautiful Tree  [2162G]
 * Problem:  https://codeforces.com/problemset/problem/2162/G
 * Verdict:  ACCEPTED        Solved: 2025-10-19
 * Language: C++20 (GCC 13-64)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math, probabilities, trees
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2162/submission/344579114
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n==2){
        cout << -1 << '\n';
        return;
    }
    if(n==3){
        cout << "1 3\n2 3\n";
        return;
    }
    if(n==4){
        cout << "1 2\n3 1\n4 1\n";
        return;
    }
    cout << "1 3\n4 3\n" << n << " 3\n";
    for(int i=3; i<n; i++){
        if(i==4) continue;
        cout << i << " " << 2 << '\n';
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--)
    solve();
    return 0;
}