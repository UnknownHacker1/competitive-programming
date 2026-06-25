/*
 * Weakness and Poorness  [578C]
 * Problem:  https://codeforces.com/problemset/problem/578/C
 * Verdict:  ACCEPTED        Solved: 2023-06-03
 * Language: C++20 (GCC 11-64)
 * Runtime:  124 ms     Memory: 800 KB
 * Tags:     ternary search
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/578/submission/208321105
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
int n;
int a[N];
double f(double x){
    double ret = 0, cur = 0, mn = 0, mx = 0;
    for(int i = 0; i < n; i++){
        cur += a[i] - x; 
        ret = max(ret, abs(cur - mn));
        ret = max(ret, abs(cur - mx));
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    return ret;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);     
    cin>>n;
    for(int i = 0; i < n; ++i)cin>>a[i]; 
    double l = -1e4, r = 1e4, eps = 1e-11;
    while(r - l > eps){
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if(f(mid1) >= f(mid2)){
            l = mid1;
        }else r = mid2;
    }
    cout<<setprecision(7)<<fixed<<f((l+r)*0.5)<<'\n';
    return 0;
}