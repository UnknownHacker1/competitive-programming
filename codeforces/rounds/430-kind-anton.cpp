/*
 * Kind Anton  [1333B]
 * Problem:  https://codeforces.com/problemset/problem/1333/B
 * Verdict:  ACCEPTED        Solved: 2022-08-24
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 400 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1333/submission/169557095
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename t1>
using ordered_set = tree<t1, null_type,less<t1>, rb_tree_tag,tree_order_statistics_node_update>;
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
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
tc{ 
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    bool neg=0,pos=0;
    bool ok = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        if(x < a[i] && neg == 0)ok = 0;
        else if(x > a[i] && pos == 0)ok = 0;
        neg |= a[i] < 0;
        pos |= a[i] > 0;
    }
    cout<<(ok ? "YES\n" : "NO\n");
}
}   