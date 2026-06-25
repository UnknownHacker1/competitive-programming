/*
 * Primitive Primes  [1316C]
 * Problem:  https://codeforces.com/problemset/problem/1316/C
 * Verdict:  ACCEPTED        Solved: 2021-12-31
 * Language: C++20 (GCC 11-64)
 * Runtime:  296 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math, ternary search
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1316/submission/141269104
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
    int n,m,p;
    cin>>n>>m>>p; 
    int x = 0;
    bool flag1=0,flag2=0;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        if(a%p!=0 && flag1==0){
            x+=i; 
            flag1=1;
        }
    }
    for(int i = 0; i < m; i++){
        int b;
        cin>>b;
        if(b%p!=0 && flag2==0){
            x+=i;
            flag2=1;
        }
    }
    cout<<x;
}
