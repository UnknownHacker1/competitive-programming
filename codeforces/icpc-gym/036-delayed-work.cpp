/*
 * Delayed Work  [101652Y]
 * Problem:  Gym/ICPC contest 101652 - problem Y
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  77 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345432264
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);     
    
    double k,p,x;
    cin >> k >> p >> x;

    double ans = 1e9;

    for(double m = 1; m <= 1e6; m++){
        ans = min(ans, m*x + k/m*p);
    }
    cout << fixed << setprecision(3) << ans;

    return 0;
}
