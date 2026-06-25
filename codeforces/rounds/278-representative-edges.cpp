/*
 * Representative Edges  [1616C]
 * Problem:  https://codeforces.com/problemset/problem/1616/C
 * Verdict:  ACCEPTED        Solved: 2021-12-29
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     brute force, geometry, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1616/submission/141094122
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
int f(vector<int>&arr) {
    if((int)arr.size() < 3) { return 0; }
    int ret = (int)arr.size();
    for(int i = 0; i < (int)arr.size() - 1; i++) {
        for(int j = i + 1; j < (int)arr.size(); j++) {
            double delta = (arr[j] - arr[i] * 1.0) / (j - i * 1.0);
            int cost = 0;
            for(int k = 0; k < (int)arr.size(); k++) {
                if(k == i) { continue; }
                if((arr[k] + delta * 1.0 * (i - k)) != arr[i]) { cost++; }
            }
            if(cost < ret) { ret = cost; }
        }
    }
    return ret;
}
int main()
{
    ACPLS();  
tc{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    cout<<f(a)<<'\n';
}
}