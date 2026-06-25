/*
 * Do You Love Your Hero and His Two-Hit Multi-Target Attacks?  [2072E]
 * Problem:  https://codeforces.com/problemset/problem/2072/E
 * Verdict:  ACCEPTED        Solved: 2025-02-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  187 ms     Memory: 0 KB
 * Tags:     binary search, brute force, constructive algorithms, dp, geometry, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2072/submission/307738798
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
        int k;
        cin>>k;
        int dummy1=1e9, dummy=1e9;
        vector<pair<int,int>>ans;
        for(int n = 500; n >= 2; n--){
            while(k >= n * (n - 1) / 2){
                k -= n * (n - 1) / 2;
                for(int i = 0; i < n; i++){
                    ans.push_back({dummy1,dummy--});
                }
                --dummy1;
            }
        }
        cout<<(int)ans.size()<<'\n';
        for(auto&p:ans)cout<<p.first<<' '<<p.second<<'\n';
    }
	return 0;
}
