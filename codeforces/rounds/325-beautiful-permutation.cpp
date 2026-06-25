/*
 * Beautiful Permutation  [2162D]
 * Problem:  https://codeforces.com/problemset/problem/2162/D
 * Verdict:  ACCEPTED        Solved: 2025-10-19
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  437 ms     Memory: 100 KB
 * Tags:     binary search, interactive
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2162/submission/344576780
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);     

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"1 1 "<<n<<endl;
        ll sum1,sum2;
        cin>>sum1; 
        cout<<endl;
        cout<<"2 1 "<<n<<endl;
        cin>>sum2; 
        cout<<endl;
        int sz = sum2-sum1;

        int l = 1, r = n; 
        while(l < r){
            int mid = (l + r) >> 1;
            cout<<"1 "<<l<<' '<<mid<<endl;
            cin>>sum1;
            cout<<endl;
            cout<<"2 "<<l<<' '<<mid<<endl;
            cin>>sum2;
            cout<<endl;
            if(sum2>sum1) r = mid;
            else l = mid + 1;
        }
        cout<<"! "<<l<<' '<<l+sz-1<<endl;
    }

    return 0;
}