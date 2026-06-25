/*
 * Cleaning the Phone  [1475D]
 * Problem:  https://codeforces.com/problemset/problem/1475/D
 * Verdict:  ACCEPTED        Solved: 2022-06-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 5700 KB
 * Tags:     binary search, dp, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1475/submission/160384760
 */

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
#define tc int tttt;cin>>tttt;while(tttt--)
int main()
{
    ACPLS(); 
tc{
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[n];
    for(auto&i:arr1)cin>>i;
    for(auto&i:arr2)cin>>i;
    vector<ll>a,b;
    for(int i = 0; i < n; i++){
        if(arr2[i]==2)
            a.push_back(arr1[i]);
        else
            b.push_back(arr1[i]);
    }    
    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    int n1 = (int)a.size(), n2 = (int)b.size();
    for(int i = 1; i < n2; i++){
        b[i]+=b[i-1];
    }
    ll ans=-1,cur=0;
    for(int i = 0; i <= n1; i++){
        if(i)cur+=a[i-1];
        if(cur>=m){
            if(ans==-1)ans=2*i;
            else ans=min(ans,2ll*i);
            continue;
        }
        int idx=lower_bound(b.begin(),b.end(),m-cur)-b.begin();
        if(idx==n2)continue;
        if(ans==-1)ans=2*i+idx+1;
        else ans=min(ans,2ll*i+idx+1);
    }
    cout<<ans<<'\n';
}
}