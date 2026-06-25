/*
 * Bouquet (Easy Version)  [1995B1]
 * Problem:  https://codeforces.com/problemset/problem/1995/B1
 * Verdict:  ACCEPTED        Solved: 2025-03-15
 * Language: C++17 (GCC 7-32)
 * Runtime:  186 ms     Memory: 4700 KB
 * Tags:     binary search, brute force, greedy, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1995/submission/310794974
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
        ll m;
        cin>>n>>m;
        map<int,ll>freq{};
        int x;
        for(int i = 0; i < n; i++){
            cin>>x;
            ++freq[x];
        }
        ll ans = min(m/(freq.begin()->first), freq.begin()->second) * (freq.begin()->first);
        for(auto it = freq.begin(); next(it) != freq.end(); ++it){ 
            ll fr1 = it->second, fr2 = next(it)->second;
            int x = it->first;
            for(ll i = 0; i * x <= m && i <= fr1; i++){
                ll take = min((m-(i * x))/(x+1), fr2);
                ans = max(ans,i*x);
                if(x+1==next(it)->first) ans = max(ans, i * x + take*(x+1));
            }
        }
        auto it = prev(freq.end());
        ans = max(ans,min(m/it->first, it->second)*it->first);
        cout<<ans<<'\n';
    }
    return 0;
}