/*
 * Max and Mex  [1496B]
 * Problem:  https://codeforces.com/problemset/problem/1496/B
 * Verdict:  ACCEPTED        Solved: 2021-12-30
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 5800 KB
 * Tags:     math
 * Author:   team "Za Nakebo Pie" (Mr.Pie, BidoTeima)
 * Source:   https://codeforces.com/contest/1496/submission/141186856
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
vector<int>v;
pair<int,int>getmex()
{
    sort(v.begin(),v.end());
    int c=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==c)c++;
    }
    return {c,v.back()};
}
void solve()
{
    v.clear();
   int n,k;
   cin>>n>>k;
   set<int>st;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       v.pb(x);
       st.insert(x);
   }
   if(k == 0)
   {
       cout<<n<<endl;
       return;
   }
    //for(k=1;k<=15;k++)
   // {
        pair<int,int>xx=getmex();
       int mex = xx.first;
       int mx=xx.second;
      // v.pb((mex+mx)/2 + ((mex+mx)%2));
      /* for(int i=0;i<v.size();i++)
       {
           cout<<v[i]<<" ";
       }
       cout<<endl;*/
       if(mex>mx)
       {
           cout<<mex+k<<endl;
           return;
       }
       else
       {
            st.insert((mex+mx)/2 + ((mex+mx)%2));
            cout<<st.size()<<endl;
            return;
       }

    //}



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
