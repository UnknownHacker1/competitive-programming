/*
 * COCI '07 Contest 3 #5 Cudak  [coci07c3p5]
 * Problem:  https://dmoj.ca/problem/coci07c3p5
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-05-14
 * Language: C++20
 * Runtime:  0.033762648 s     Memory: 3568.0 KB
 * Source:   https://dmoj.ca/src/5541113
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <memory.h>
using namespace std;
using ll = long long;
int n;
ll lim_l, lim_r;
vector<int>l,r;
ll dp[20][150][2][2];
ll rec(int idx, int s, bool greater_l, bool smaller_r){
    if(s < 0)
        return 0;
    if(idx == n)
        return (s == 0);
    if(dp[idx][s][greater_l][smaller_r] != -1)
        return dp[idx][s][greater_l][smaller_r];
    int i = l[idx], j = r[idx];
    if(greater_l) i = 0;
    if(smaller_r) j = 9;
    ll ret = 0;
    for(int d = i; d <= j; d++){
        ret += rec(idx + 1, s - d, greater_l || (d > i), smaller_r || (d < j));
    }
    return dp[idx][s][greater_l][smaller_r]=ret;
}
ll mn;
bool built = 0;
void build(int idx, int s, bool greater_l, bool smaller_r){
    if(idx == n)
        return;
    int i = l[idx], j = r[idx];
    if(greater_l) i = 0;
    if(smaller_r) j = 9;
    for(int d = i; d <= j; d++){
        if(rec(idx + 1, s - d, greater_l || (d > i), smaller_r || (d < j))){
            mn *= 10, mn += d;
            build(idx + 1, s - d, greater_l || (d > i), smaller_r || (d < j));
            break;
        }
    }
}
int len(ll x){
    int ret = 0;
    while(x){
        x /= 10;
        ret++;
    }
    return ret;
}
int main()
{         
    ll a,b;
    int s;
    cin>>a>>b>>s;
    int len_a = len(a), len_b = len(b);
    ll ans = 0;
    for(n = len_a; n <= len_b; n++){
        memset(dp, -1, sizeof(dp));
        lim_l = a, lim_r = b;
        if(len_a < n){
            lim_l = 1;
            for(int i = 1; i < n; i++){
                lim_l *= 10;
            }
        }
        if(len_b > n){
            lim_r = 0;
            for(int i = 0; i < n; i++){
                lim_r *= 10, lim_r += 9;
            }
        }
        while(lim_l){
            l.push_back(lim_l % 10);
            lim_l /= 10;
        }
        reverse(l.begin(), l.end());
        while(lim_r){
            r.push_back(lim_r % 10);
            lim_r /= 10;
        }
        reverse(r.begin(), r.end());
        ll add = rec(0, s, 0, 0);
        ans += add;
        if(built == 0 && add){
            build(0, s, 0, 0);
            built = 1;
        }
    }
    cout<<ans<<'\n'<<mn<<'\n';
    return 0;
}