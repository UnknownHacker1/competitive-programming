/*
 * Splitting Items  [2004C]
 * Problem:  https://codeforces.com/problemset/problem/2004/C
 * Verdict:  ACCEPTED        Solved: 2025-03-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  109 ms     Memory: 100 KB
 * Tags:     games, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2004/submission/308928316
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
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        } 
        sort(a,a+n);reverse(a,a+n);
        ll ans = a[0];
        for(int i = 1; i < n; i++){
            if(i & 1){
                int add = min(k, a[i - 1] - a[i]);
                a[i] += add;
                k -= add;
                ans -= a[i];
            }
            else ans += a[i];
        }
        cout<<ans<<'\n';
    }

	return 0;
}
