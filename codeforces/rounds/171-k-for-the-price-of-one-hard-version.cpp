/*
 * K for the Price of One (Hard Version)  [1282B2]
 * Problem:  https://codeforces.com/problemset/problem/1282/B2
 * Verdict:  ACCEPTED        Solved: 2022-01-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 1600 KB
 * Tags:     dp, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1282/submission/142187258
 */

#include<bits/stdc++.h> /// BY ABDO AND BIDO
#define int long long
#define pb push_back
#define fword ios_base::sync_with_stdio(0);cin.tie(0);
#define For(s,n) for(int i=s;i<=n;i++)
#define endl '\n'
using namespace std;
const int mod  = 1000000007;
void solve()
{
   int n,p,k;
   cin>>n>>p>>k;
   int ans=0;
   int sum=0;
   int arr[n];
   For(0,n-1)
   {
       cin>>arr[i];
   }
   sort(arr,arr+n);
   //This was the error cuz i dont need to look beyond k cuz the inner loop handles that
   for(int i=0;i<=k;i++)
   {
       //take first i elements as singles
        int c=i;
        int temsum=sum;
        if(temsum>p)
        {
            break;
        }
        for(int j=i+k-1;j<n;j+=k)
        {
            //try to take k segments as long as its possible
           if(temsum+arr[j]<=p)
           {
               temsum+=arr[j];
               c+=k;
           }
           else
           {
               //if not possible dont waste time and break
               break;
           }
        }
        //now add the single element to the sum
        //cuz its somehow better to take 1 instead of k
        sum+=arr[i];
        //maximize ans
        ans=max(ans,c);
 
   }
   cout<<ans<<endl;
  /* for(int i=0;i<n;i++)
   {
       cout<<arr2[i]<<" ";
   }
   cout<<endl;*/
 
}
int32_t main()
{
    fword;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
