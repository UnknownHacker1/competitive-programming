/*
 * Star Arrangements  [101652X]
 * Problem:  Gym/ICPC contest 101652 - problem X
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345431628
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);        

    int S;
    cin >> S;
    
    set<pair<int,int>> st;

    for(int x = 1; x < S; x++){
        if(S % (2 * x + 1) == 0){
            st.insert({x + 1, x});
        }
        if(S % x == 0){
            st.insert({x, x});
        }
        // (a + 1)(x + 1) + a(x) = S
        // a(x + 1) + (x + 1) + a(x) = S
        // a(2x + 1) = S - (x + 1)
        // a = (S - (x + 1))/(2x + 1)

        if(S > (x + 1) && (S - (x + 1)) % (2 * x + 1) == 0){
            st.insert({x + 1, x});
        } 
    }
    cout<<S<<":\n";
    for(auto&it : st){
        if(it.first == 1 || it.first == S) continue;
        cout << it.first << ',' << it.second << '\n';
    }

    return 0;
}
