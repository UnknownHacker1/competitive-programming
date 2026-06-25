/*
 * Economy Game  [681B]
 * Problem:  https://codeforces.com/problemset/problem/681/B
 * Verdict:  ACCEPTED        Solved: 2022-02-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/681/submission/145841950
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
int main()
{
    ACPLS();
    ll n;
    cin>>n;
    for(ll a = 0; a <= 810; a++){
        for(ll b = 0; b <= 8100; b++){
            ll rem = n-a*1234567-b*123456;
            if(rem>=0&&rem%1234==0){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}


