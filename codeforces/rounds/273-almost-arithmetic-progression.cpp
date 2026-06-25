/*
 * Almost Arithmetic Progression  [978D]
 * Problem:  https://codeforces.com/problemset/problem/978/D
 * Verdict:  ACCEPTED        Solved: 2022-02-07
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 800 KB
 * Tags:     brute force, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/978/submission/145570831
 */

/// isA AC
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")

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
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    if(n<=2){
        cout<<"0\n";
        return 0;
    }
    int ans=1e9;
    for(int m1=-1; m1<=1; m1++){
        for(int m2=-1; m2<=1; m2++){
            int copya[n];
            for(int i = 0; i < n; i++)
                copya[i]=a[i];
            int cnt=(!!m1)+(!!m2);
            copya[0]+=m1;
            copya[1]+=m2;
            int diff = (copya[1])-(copya[0]);
            for(int i = 2; i < n; i++){
                if(copya[i]+1-copya[i-1]==diff){
                    copya[i]++;
                    cnt++;
                }
                else if(copya[i]-1-copya[i-1]==diff){
                    cnt++;
                    copya[i]--;
                }
                else if(copya[i]-copya[i-1]==diff){}
                else cnt=1e9;
            }
            ans=min(ans,cnt);
        }
    }
    if(ans==1e9)
        cout<<-1;
    else cout<<ans;
}


