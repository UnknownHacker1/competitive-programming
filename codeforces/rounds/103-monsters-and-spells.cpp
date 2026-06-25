/*
 * Monsters And Spells  [1626C]
 * Problem:  https://codeforces.com/problemset/problem/1626/C
 * Verdict:  ACCEPTED        Solved: 2022-03-30
 * Language: C++17 (GCC 9-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     binary search, data structures, dp, greedy, implementation, math, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1626/submission/151439475
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
 
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()  
int n;
ll k[105],h[105];
pair<ll,ll>mx[105];
bool check(ll start, pair<ll,ll>p){
    return p.second-start+1>=p.first+p.second;
}
int main()
{
    ACPLS();    
tc{
    cin>>n;  
    for(int i = 0; i < n; i++)cin>>k[i];
    for(int i = 0; i < n; i++)cin>>h[i]; 
    mx[n-1]={h[n-1]-k[n-1],k[n-1]};
    for(int i = n-2; i >= 0; i--){
        mx[i]=max(mx[i+1],{h[i]-k[i],k[i]});
    }
    ll cur=1,ans=0,curplsequal=0;
    for(int i = 0; i < n; i++){
        int lo = (i==0?1:k[i-1]+1), hi = k[i], res = -1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(check(mid,mx[i])){
                res=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        if(res!=-1){
            cur=res;
            curplsequal=0;
        } 
        ans+=(k[i]-cur+1)*(k[i]-cur+2)/2-curplsequal;
        curplsequal=(k[i]-cur+1)*(k[i]-cur+2)/2;
    }
    cout<<ans<<'\n';
}
}