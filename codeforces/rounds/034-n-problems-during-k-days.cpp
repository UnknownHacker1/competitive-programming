/*
 * N Problems During K Days  [1157D]
 * Problem:  https://codeforces.com/problemset/problem/1157/D
 * Verdict:  ACCEPTED        Solved: 2022-08-24
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 200 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1157/submission/169525955
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
    int n, k;
    cin>>n>>k;
    int s = n;
    if(k * 1ll * (k + 1) / 2 > n)
        return cout<<"NO", 0;
    n -= k * 1ll * (k + 1) / 2;
    int ans[k];
    for(int i = 0; i < k; i++)ans[i] = 1;
    for(int i = 0; i < k; i++){
        int inc = (i == 0? n / k : min(n / (k - i), ans[i - 1] - ans[i]));
        n -= inc * (k - i);
        ans[i] += inc;
        if(i)ans[i] += ans[i-1];
        s -= ans[i];
    }   
    assert(s>=0);
    if(s>0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        for(int i = 0; i < k; i++){
            cout<<ans[i]<<' ';
        }
    }
     
}   