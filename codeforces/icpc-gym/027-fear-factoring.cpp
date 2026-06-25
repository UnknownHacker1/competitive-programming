/*
 * Fear Factoring  [101652P]
 * Problem:  Gym/ICPC contest 101652 - problem P
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  218 ms     Memory: 100 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345429808
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    


__int128 sum(__int128 l, __int128 r){
    return r*(r+1)/2-l*(l-1)/2;
}

__int128 f(__int128 n){
    __int128 cur=1, curCnt=n;
    __int128 ret = 0;
    while(curCnt > 1){
        __int128 x = n/curCnt;

        ret+=sum(cur,x)*curCnt;

        cur=x+1;

        curCnt = n/cur;
    }

    return ret+sum(cur, n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);       

    ll a,b;
    cin>>a>>b;

    cout << ll(f(b) - (a == 1 ? 0 : f(a - 1)));
    
    return 0;
}
