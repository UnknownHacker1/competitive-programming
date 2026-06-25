/*
 * The Meeting Place Cannot Be Changed  [780B]
 * Problem:  https://codeforces.com/problemset/problem/780/B
 * Verdict:  ACCEPTED        Solved: 2022-02-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 1000 KB
 * Tags:     binary search
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/780/submission/145230400
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
ll x[60005],v[60005];
bool check(double ans, int n){
    pair<double,double>intersection={-1e9,1e9};
    for(int i = 0; i < n; i++){
        double f = 1.0*x[i]-1.0*ans*1.0*v[i];
        double s = 1.0*x[i]+1.0*ans*1.0*v[i];
        intersection.first=max(intersection.first,f);
        intersection.second=min(intersection.second,s);
        if(intersection.first>intersection.second)
            return 0;
    }
    return 1;
}
int main()
{
    ACPLS();
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>x[i];
    for(int i = 0; i < n; i++)
        cin>>v[i];
    double lo=0.f,hi=1e9f,ans=hi;
    for(int it = 0; it < 500; it++){
        double mid = 0.5*(lo+hi);
        if(check(mid,n))
            hi=mid,ans=mid;
        else
            lo=mid;
    }
    cout<<setprecision(6)<<fixed<<ans;
}


