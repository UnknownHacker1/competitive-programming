/*
 * Strange Definition  [1470B]
 * Problem:  https://codeforces.com/problemset/problem/1470/B
 * Verdict:  ACCEPTED        Solved: 2021-12-08
 * Language: C++20 (GCC 11-64)
 * Runtime:  436 ms     Memory: 19200 KB
 * Tags:     bitmasks, graphs, hashing, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1470/submission/138457771
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int leastprime[(int)1e6+5];
void sieve(int n){
    ++n;
    for(ll i = 2; i <= n; i++){
        for(ll j = i*i; j <= n; j+=i){
            if(!leastprime[j])
                leastprime[j]=i;
        }
    }
}
int main()
{
    ACPLS();   
    sieve(1e6);
tc{
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    map<int,int>freq{};
    for(int i:a){
        map<int,int>fact{};
        while(leastprime[i]!=0){
            ++fact[leastprime[i]];
            i/=leastprime[i];
        }
        if(i>1)++fact[i];
        int x = 1;
        for(auto y:fact){
            if(y.second&1)
                x*=y.first;
        }
        ++freq[x];
    }
    int ans1=1;
    for(auto y:freq)
        ans1=max(ans1,y.second);
    int ans2=0;
    for(auto y:freq){
        if(y.second%2==0||y.first==1)
            ans2+=y.second;
    }
    int q;
    cin>>q;
    while(q--){
        ll w;
        cin>>w;
        if(w==0)cout<<ans1<<'\n';
        else cout<<max(ans1,ans2)<<'\n';
    }
}
}
