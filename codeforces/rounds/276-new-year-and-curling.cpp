/*
 * New Year and Curling  [908C]
 * Problem:  https://codeforces.com/problemset/problem/908/C
 * Verdict:  ACCEPTED        Solved: 2022-01-11
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, geometry, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/908/submission/142373877
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
double sqr(double v){
    return v*v;
}
double solve(double a, double b, double d, double r){
    if((2*r+a-b)*(2*r-a+b) < 0)
        return -1;
    return sqrt((2*r+a-b)*(2*r-a+b))+d;
}
int main()
{
    ACPLS();  
    int n,r;
    cin>>n>>r;
    int x[n];
    for(auto&i:x)cin>>i;
    double y[n];
    y[0]=r;
    cout<<fixed<<setprecision(6);
    cout<<y[0]<<' ';
    for(int i = 1; i < n; i++){
        double mxy2=r;
        for(int j = 0; j < i; j++){
            double x1=x[j],x2=x[i],y1=y[j];
            mxy2=max(mxy2,solve(x2,x1,y1,r));
        }
        y[i]=mxy2;
        cout<<y[i]<<' ';
    }
}
 
