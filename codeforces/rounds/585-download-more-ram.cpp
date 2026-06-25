/*
 * Download More RAM  [1629A]
 * Problem:  https://codeforces.com/problemset/problem/1629/A
 * Verdict:  ACCEPTED        Solved: 2022-01-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     brute force, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1629/submission/143722040
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
tc{
    int n,k;
    cin>>n>>k;
    pair<int,int>arr[n];
    for(auto&i:arr)cin>>i.first;
    for(auto&i:arr)cin>>i.second;
    sort(arr,arr+n);
    for(int i = 0; i < n; i++){
        if(k>=arr[i].first){
            k+=arr[i].second;
        }
    }
    cout<<k<<'\n';
}
}
