/*
 * IOI '04 P5 - Farmer  [ioi04p5]
 * Problem:  https://dmoj.ca/problem/ioi04p5
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-06-26
 * Language: C++17
 * Runtime:  1.498042472 s     Memory: 3840.0 KB
 * Source:   https://dmoj.ca/src/5609606
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int q,m,k,n;
    cin>>q>>m>>k;
    multiset<int>s1,s2;
    for(int i = 0; i < m; i++){
        cin>>n;
        s1.insert(n);
        s2.insert(n);
    }
    for(int i = 0; i < k; i++){
        cin>>n;
        s2.insert(n);
    }
    bool can[q + 1]={0};
    can[0] = 1;
    for(auto it = s1.begin(); it != s1.end(); ++it){
        for(int i = q; i >= 0; i--){
            if(can[i] && i + (*it) <= q){
                can[i + (*it)] = 1;
            }
        }
    }
    if(can[q]){
        return cout<<q, 0;
    }
    ll ans = 0;
    multiset<int>::iterator it;
    while(!s1.empty() && (it = s1.upper_bound(q)) != s1.begin()){
        it = prev(it); 
        q -= *it;
        ans += *it;
        s2.erase(s2.find(*it));
        s1.erase(s1.find(*it));
    }
    while(!s2.empty() && q > 0){
        it = prev(s2.end());
        int x = min(q, *it);
        q -= x;
        ans += x - 1;
        s2.erase(s2.find(*it));
    }
    cout<<ans;
    return 0;
}