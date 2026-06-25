/*
 * Trinity  [2032C]
 * Problem:  https://codeforces.com/problemset/problem/2032/C
 * Verdict:  ACCEPTED        Solved: 2025-03-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  109 ms     Memory: 0 KB
 * Tags:     binary search, math, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2032/submission/308710626
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);  
        if(a[0] + a[1] > a[n - 1]){
            cout<<"0\n";
            continue;
        } 

        //cout<<'\n';
        int ans = n;
        for(int i = 0; i < n; i++){
            // set a_[0, i - 1] = a[i]
            // set a_[res + 1, n - 1] = a[res]
            int lo = i, hi = n - 1, mid, res = i;
            while(lo <= hi){
                mid = (lo + hi) >> 1;
                if(a[i] + a[i] > a[mid]){
                    lo = mid + 1;
                    res = mid;
                } else hi = mid - 1;
            }
            ans = min(ans, i + n - res - 1);
            if(i==0)continue;
            lo=i,hi=n-1,mid,res=i;
            while(lo <= hi){
                mid = (lo + hi) >> 1;
                if(a[i - 1] + a[i] > a[mid]){
                    lo=mid+1;res=mid;
                } else hi=mid-1;
            }
            ans=min(ans,i-1+n-res-1);
        }
        cout << ans << '\n';
    }
	return 0;
}
