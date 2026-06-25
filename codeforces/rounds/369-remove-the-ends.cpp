/*
 * Remove the Ends  [2064C]
 * Problem:  https://codeforces.com/problemset/problem/2064/C
 * Verdict:  ACCEPTED        Solved: 2025-04-29
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  93 ms     Memory: 100 KB
 * Tags:     brute force, constructive algorithms, dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2064/submission/317752247
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){  
        int n;
        cin>>n;
        int a[n];
        ll suff[n];
        for(auto&i:a)cin>>i;
        suff[n-1]=(a[n-1]<0?-a[n-1]:0);
        for(int i = n - 2; i >= 0; i--){
            suff[i]=suff[i+1];
            if(a[i]<0)suff[i]-=a[i];
        }
        ll sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i]>0)sum += a[i];
            ans=max(ans,sum+suff[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}