/*
 * OKEA  [1634C]
 * Problem:  https://codeforces.com/problemset/problem/1634/C
 * Verdict:  ACCEPTED        Solved: 2022-02-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  514 ms     Memory: 2900 KB
 * Tags:     constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1634/submission/145437490
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
    int a[n+1][k+1];
    ll pref[n+1][k+1]={0};
    bool can = 1;
    for(int i = 1; i <= n; i++){
        a[i][1]=i;  
        pref[i][1]=i;
        for(int j = 2; j <= k; j++){
            a[i][j]=a[i][j-1]+n; 
            pref[i][j]=pref[i][j-1]+a[i][j];
        } 
    }
    if(a[n][k]!=n*k)can=0;

    for(int i = 1; i <= n; i++){
        for(int l = 1; l <= k; l++){
            for(int r = l; r <= k; r++){
                if(sumrange(l,r,pref[i])%(r-l+1)!=0){
                    can=0;break;
                }
            }
        }
    }
    if(!can){
        cout<<"NO\n";
        continue;
    }
    cout<<"YES\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}
}


