/*
 * Robin Hood in Town  [2014C]
 * Problem:  https://codeforces.com/problemset/problem/2014/C
 * Verdict:  ACCEPTED        Solved: 2025-04-29
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  171 ms     Memory: 0 KB
 * Tags:     binary search, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2014/submission/317750078
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
        ll s = 0;
        for(auto&i:a)cin>>i,s+=i;
        int mx=*max_element(a,a+n);
        ll lo=0,hi=1e15,mid,ans=-1;
        while(lo<=hi){
            mid=(lo+hi)>>1;
            int cnt = 0;
            bool skip1=0;
            for(int i = 0; i < n; i++){
                if(!skip1&&a[i]==mx){
                    skip1=1;
                    continue;
                }
                if(2 * a[i] < (s + mid + n-1) / n){
                    cnt++;
                }
            }
            if(cnt > (n/2)){
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}