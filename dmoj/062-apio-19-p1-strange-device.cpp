/*
 * APIO '19 P1 - Strange Device  [apio19p1]
 * Problem:  https://dmoj.ca/problem/apio19p1
 * Verdict:  ACCEPTED (20.0 pts)   Solved: 2024-03-28
 * Language: C++20
 * Runtime:  6.239563228 s     Memory: 19612.0 KB
 * Source:   https://dmoj.ca/src/6309380
 */

#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int n;
    ll a,b;
    cin>>n>>a>>b;
    ll d = a/__gcd(a,b+1)*b;
    vector<pair<ll,ll>>v;
    for(int i = 0; i < n; i++){
        ll l,r;
        cin>>l>>r; 
        if(r - l + 1 >= d){
            return cout<<d, 0;
        }
        //if(r%d>l%d) push from l%d to r%d 
        //otherwise push [l%d,d-1] & [0,r%d]
        if(r%d >= l%d)v.push_back({l%d, r%d});
        else{
            v.push_back({l%d, d - 1});
            v.push_back({0, r%d});
        }
    } 
    sort(v.begin(),v.end());
    //cout<<v[0].first<<' '<<v[0].second<<'\n';
    ll curL=v[0].first,curR=v[0].second, ans = 0;
    for(int i = 1; i < (int)v.size(); i++){
        //cout<<v[i].first<<' '<<v[i].second<<'\n';
        if(v[i].first <= curR){ 
            curR=max(curR, v[i].second);
        }else{
            ans += curR-curL+1;
            tie(curL,curR) = v[i];
        }
    }
    cout<<ans+curR-curL+1;
    return 0;
}