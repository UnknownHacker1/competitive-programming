/*
 * Integer Diversity  [1616A]
 * Problem:  https://codeforces.com/problemset/problem/1616/A
 * Verdict:  ACCEPTED        Solved: 2021-12-29
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1616/submission/141046475
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
    int n;
    cin>>n;
    int a[n];
    map<int,int>freq{};
    for(auto&i:a)cin>>i,++freq[i];
    int ans=0;
    for(int i = -100; i <= 100; i++){
        if(freq[i]>1&&freq[-i]==0){
            ans+=2;
        }
        else if(freq[i]>0){
            ans+=1;
        }
    }
    cout<<ans<<'\n';
}
}