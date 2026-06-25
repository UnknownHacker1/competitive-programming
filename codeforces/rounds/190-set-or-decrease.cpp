/*
 * Set or Decrease  [1622C]
 * Problem:  https://codeforces.com/problemset/problem/1622/C
 * Verdict:  ACCEPTED        Solved: 2024-04-21
 * Language: C++20 (GCC 13-64)
 * Runtime:  124 ms     Memory: 0 KB
 * Tags:     binary search, brute force, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1622/submission/257562293
 */

#include <bits/stdc++.h> 
using namespace std;  
#define int long long
using ll = long long;   

int32_t main(){  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
        int n;
        ll k;
        cin>>n>>k;
        int a[n];
        for(int&i:a)cin>>i;
        ll d = accumulate(a,a+n,0ll)-k;
        if(d<=0){
            cout<<"0\n";
            continue;
        }
        sort(a,a+n);
        ll s=0,ans=1e15;
        for(int i = n; i >= 1; i--){
            if(i!=n)s += a[i];
            ll lo=0,hi=1e15,m,res=hi;
            while(lo<=hi){
                m=(lo+hi)>>1;
                if(n-i!=0&&(a[0]-m) <= -1e18/(n-i)){
                    res=m;
                    hi=m-1;
                    continue;
                }
                if(m + s - (a[0] - m) * (n - i) >= d){
                    res = m;
                    hi = m - 1;
                }else lo = m + 1;
            }
            ans = min(ans, res + n - i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}