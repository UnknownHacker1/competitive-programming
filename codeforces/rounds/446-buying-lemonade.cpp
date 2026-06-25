/*
 * Buying Lemonade  [2024B]
 * Problem:  https://codeforces.com/problemset/problem/2024/B
 * Verdict:  ACCEPTED        Solved: 2025-03-05
 * Language: C++17 (GCC 7-32)
 * Runtime:  171 ms     Memory: 3400 KB
 * Tags:     binary search, constructive algorithms, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2024/submission/309062232
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
        map<int,int>freq{};
        for(int i = 0; i < n; i++){
            cin>>a[i];freq[a[i]]++;
        }
        ll ans = 0, smfreq=0, prevf=0,prevv=0;
        for(auto& it : freq){ 
            ans += prevf;
            ll take = (it.first-prevv) * (n - smfreq);
            if(k < take) break;
            ans += take;
            k -= take;
            smfreq += it.second;
            prevf = it.second;
            prevv = it.first;
            if(k == 0)break;
        }
        cout << ans + k << '\n';
    }
	return 0;
}
