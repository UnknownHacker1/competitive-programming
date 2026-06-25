/*
 * Increase/Decrease/Copy  [1976B]
 * Problem:  https://codeforces.com/problemset/problem/1976/B
 * Verdict:  ACCEPTED        Solved: 2025-03-09
 * Language: C++17 (GCC 7-32)
 * Runtime:  140 ms     Memory: 4200 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1976/submission/309670698
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  
const int N = 2e5 + 3; 

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        ll a[n],b[n+1];
        for(auto&i:a)cin>>i;
        for(auto&i:b)cin>>i;
        ll ans = 0, bNCost=1e18;
        for(int i = 0; i < n; i++){ 
            int l = min(a[i],b[i]), r = max(a[i],b[i]);
            if(l <= b[n] && b[n] <= r) bNCost = 0;
            else bNCost = min({bNCost, abs(b[n]-l), abs(b[n]-r)});
            ans += r - l;
        }
        ans += bNCost + 1;
        cout << ans << '\n';
    }
    return 0;
}
