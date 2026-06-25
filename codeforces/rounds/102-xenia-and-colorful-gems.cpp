/*
 * Xenia and Colorful Gems  [1336B]
 * Problem:  https://codeforces.com/problemset/problem/1336/B
 * Verdict:  ACCEPTED        Solved: 2021-09-05
 * Language: C++17 (GCC 7-32)
 * Runtime:  187 ms     Memory: 6000 KB
 * Tags:     binary search, greedy, math, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1336/submission/127914852
 */

/// Solved by Bido and Mr.Try_Harder
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
//#define endl '\n'
const int mod = 1e9+7;
using namespace std;
/*__int128 POW(int64_t a, int64_t b,int64_t mod)
{
    if(b==0) return 1;
    a%=mod;
    __int128 res = POW(a,b/2,mod);
    if(b&1)
        return (__int128)((res%mod*res%mod*a%mod)%mod);
    return (__int128)((res%mod*res%mod)%mod);
}*/
int ans(int r,int g,int b,int rr[],int gg[],int bb[])
{
    int an=4e18;
    for(int i=0;i<r;i++)
    {
        int a=lower_bound(gg,gg+g,rr[i])-gg;
        if(a == g)continue;
        int c=upper_bound(bb,bb+b,rr[i])-bb;
        if(c == 0)continue;
        int x = rr[i];
        int y = gg[a];
        int z = bb[c-1];
        an=min(an,(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
    }
    return an;
}
void solve()
{
    /// Solved by Bido and Mr.Try_Harder
    int r,g,b;
    cin>>r>>g>>b;
    int x,y,z;
   // cin>>x>>y>>z;
    //cout<<(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x)<<endl;
    int rr[r],gg[g],bb[b];
    for(auto &i:rr)cin>>i;
    for(auto &i:gg)cin>>i;
    for(auto &i:bb)cin>>i;
    sort(rr,rr+r);
    sort(gg,gg+g);
    sort(bb,bb+b);
    int reans=ans(r,g,b,rr,gg,bb);
    reans=min(reans,ans(r,b,g,rr,bb,gg));
    reans=min(reans,ans(g,r,b,gg,rr,bb));
    reans=min(reans,ans(g,b,r,gg,bb,rr));
    reans=min(reans,ans(b,r,g,bb,rr,gg));
    reans=min(reans,ans(b,g,r,bb,gg,rr));
    cout<<reans<<endl;
    /// Solved by Bido and Mr.Try_Harder
}
int32_t main(){ 
    /// Solved by Bido and Mr.Try_Harder
	int t=1;
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
	while(t--){solve();}
	return 0;
	/// Solved by Bido and Mr.Try_Harder
}