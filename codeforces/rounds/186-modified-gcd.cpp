/*
 * Modified GCD  [75C]
 * Problem:  https://codeforces.com/problemset/problem/75/C
 * Verdict:  ACCEPTED        Solved: 2022-02-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     binary search, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/75/submission/145894869
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
    int a,b;
    cin>>a>>b;
    int g=__gcd(a,b);
    vector<int>div;
    for(int i = 1; i * i <= g; i++){
        if(g%i==0){
            div.push_back(i);
            if(i!=g/i){
                div.push_back(g/i);
            }
        }
    }
    sort(all(div));
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int l,r;
        cin>>l>>r;
        auto it = upper_bound(all(div),r)-1;
        if(it==prev(div.begin())||(*it)<l){
            cout<<"-1\n";
        }else cout<<*it<<'\n';
    }
}


