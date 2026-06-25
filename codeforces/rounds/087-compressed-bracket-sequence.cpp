/*
 * Compressed Bracket Sequence  [1556C]
 * Problem:  https://codeforces.com/problemset/problem/1556/C
 * Verdict:  ACCEPTED        Solved: 2022-06-21
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1556/submission/161409756
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
    int n;
    cin>>n;
    int c[n];
    for(int i = 0; i < n; i++){
        cin>>c[i];
        c[i]*=(i&1?-1:1);
    }
    ll ans=0;
    for(int i = 0; i < n; i++){
        ll mn=-1,cur=0;
        if(i&1)continue;
        for(int j = i+1; j < n; j++){
            if(j&1)
                ans+=max(0ll,min(-c[j]-cur,(ll)c[i])-max(-1-cur,abs(mn))+1);
            cur+=c[j];
            mn=min(mn,cur);
        }
    }
    cout<<ans;
}