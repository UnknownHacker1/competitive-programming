/*
 * The Secret Number  [2132B]
 * Problem:  https://codeforces.com/problemset/problem/2132/B
 * Verdict:  ACCEPTED        Solved: 2025-09-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2132/submission/337084900
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>ans;  
        for(ll c = 1,m=10; c <= 18; c++,m*=10){
            if((n)%(m+1)==0){
                ans.push_back(n/(m+1));
            }
        } 
        sort(ans.begin(),ans.end());
        cout<<(int)ans.size()<<'\n';
        for(auto&i:ans){
            cout<<i<<' ';
        }
        if(ans.size())cout<<'\n';
    }
    return 0;
}