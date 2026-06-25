/*
 * Diamond Miner  [1496C]
 * Problem:  https://codeforces.com/problemset/problem/1496/C
 * Verdict:  ACCEPTED        Solved: 2021-12-30
 * Language: C++20 (GCC 11-64)
 * Runtime:  78 ms     Memory: 3900 KB
 * Tags:     geometry, greedy, sortings
 * Author:   team "Za Nakebo Pie" (Mr.Pie, BidoTeima)
 * Source:   https://codeforces.com/contest/1496/submission/141190693
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
void solve()
{
   int n;
   cin>>n;
   vector<double>miner,mine;
   for(int i=0;i<2*n;i++)
   {
       int x,y;
       cin>>x>>y;
       if(x == 0)
       {
           miner.pb(abs(y));
       }
       else
       {
           mine.pb(abs(x));
       }
   }
   //both max
   sort(miner.begin(),miner.end());
   sort(mine.begin(),mine.end());
   double ans=0;
   for(int i=0;i<n;i++)
   {
       ans+=sqrt(miner[i]*miner[i] + mine[i]*mine[i]);
   }
   cout<<fixed<<setprecision(12)<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

}
