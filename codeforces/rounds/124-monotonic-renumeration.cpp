/*
 * Monotonic Renumeration  [1102E]
 * Problem:  https://codeforces.com/problemset/problem/1102/E
 * Verdict:  ACCEPTED        Solved: 2022-01-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  249 ms     Memory: 10300 KB
 * Tags:     combinatorics, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1102/submission/141862311
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
    map<int,int>lst{};
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        lst[a[i]]=i;
    }
    int cnt=0,cur=0;
    while(cur<n){
        int lol=cur;
        cur=lst[a[cur]]+1;
        for(int i = lol; i < cur; i++){
            cur=max(cur,lst[a[i]]+1);
        }
        ++cnt;
    }
    ll ans=1;
    for(int i = 1; i < cnt; i++){
        ans*=2;
        ans%=998244353;
    }
    cout<<ans;
}
