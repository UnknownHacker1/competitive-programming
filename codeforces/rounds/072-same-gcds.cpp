/*
 * Same GCDs  [1295D]
 * Problem:  https://codeforces.com/problemset/problem/1295/D
 * Verdict:  ACCEPTED        Solved: 2022-09-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1295/submission/170976495
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
        #ifndef ONLINE_JUDGE
            freopen("output.txt", "w", stdout);
            freopen("input.txt", "r", stdin);
        #endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()  
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    ACPLS("");  
tc{
    ll a,m;
    cin>>a>>m; 
    cout<<phi(m/__gcd(a,m))<<'\n';
}
}   