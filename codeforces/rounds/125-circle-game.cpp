/*
 * Circle Game  [1451D]
 * Problem:  https://codeforces.com/problemset/problem/1451/D
 * Verdict:  ACCEPTED        Solved: 2021-12-15
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     games, geometry, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1451/submission/139412017
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
ll sqr(ll x){
    return x*x;
}
int main()
{
    ACPLS(); 
tc{
    ll d,k;
    cin>>d>>k;
    string ans;
    for(ll i = 0; ;i++){
        if(sqr(i*k)+sqr(i*k)>sqr(d)){
            ans="Ashish";
            break;
        }
        if(sqr(i*k)+sqr((i+1)*k)>sqr(d)){
            ans="Utkarsh";
            break;
        }
    }
    cout<<ans<<'\n';
}
}
