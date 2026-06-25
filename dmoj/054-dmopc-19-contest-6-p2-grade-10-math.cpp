/*
 * DMOPC '19 Contest 6 P2 - Grade 10 Math  [dmopc19c6p2]
 * Problem:  https://dmoj.ca/problem/dmopc19c6p2
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-02-15
 * Language: C++20
 * Runtime:  0.395763739 s     Memory: 3200.0 KB
 * Source:   https://dmoj.ca/src/4343784
 */

/// ya rab AC
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
ll freq[(int)1e6+3]={0};
ll f(ll n, ll p){
    ll ret=0;
    while(n){
        ret+=n/p;
        n/=p;
    }
    return ret;
}
int main()
{
    ACPLS();   
    ll a,b;
    cin>>a>>b;
    for(ll i = 2; i <= 1e6; i++){
        while(a%i==0){
            a/=i;
            freq[i]++;
        }
    }
    ll ret = 1e9;
    for(int i = 2; i <= 1e6; i++){
       if(freq[i]==0)continue;
        ret=min(ret,f(b,i)/freq[i]);
    }
    cout<<ret;
}