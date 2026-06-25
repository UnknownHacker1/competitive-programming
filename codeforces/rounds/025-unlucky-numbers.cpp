/*
 * Unlucky Numbers  [1808C]
 * Problem:  https://codeforces.com/problemset/problem/1808/C
 * Verdict:  ACCEPTED        Solved: 2023-12-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 100 KB
 * Tags:     brute force, dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1808/submission/238425450
 */

#include <bits/stdc++.h>
#define int unsigned long long
using ll = long long;
using namespace std;
pair<int,int> len(int x){
    int ret = 0, sec = 1; 
    while(x) {
        x /= 10;
        sec*=10;
        ret++;
    }
    return {ret,sec};
}
int n;
vector<int> toVec(int x){
    vector<int>ret;
    while(x){
        ret.push_back(x % 10);
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
// 18*10*10*4 = 1800*4 = 3600*2 = 7200
// 7200 * 600 operations atmost
vector<int>l,r;
int dp[20][10][10][2][2];
int rec(int idx, int mn, int mx, bool greaterL, bool lessR){
    if(idx == (int)l.size()){
        return mx - mn;
    }
    auto& ref = dp[idx][mn][mx][greaterL][lessR];
    if(ref != -1) return ref;
    int st = greaterL ? 0 : l[idx];
    int en = lessR ? 9 : r[idx];
    int ret = 10;
    for(int d = st; d <= en; d++){
        ret = min(ret, rec(idx + 1, min(mn, d), max(mx, d), greaterL || (d > l[idx]), lessR || (d < r[idx])));
    }
    return ref = ret;
}
void build(int idx, int mn, int mx, bool greaterL, bool lessR){
    if(idx == (int)l.size()){
        return;
    }
    int st = greaterL ? 0 : l[idx];
    int en = lessR ? 9 : r[idx];
    int bestDigit = -1, value = 10;
    for(int d = st; d <= en; d++){
        int x = rec(idx + 1, min(mn, d), max(mx, d), greaterL || (d > l[idx]), lessR || (d < r[idx]));
        if(x < value){
            bestDigit = d;
            value = x;
        }
    }
    cout<<bestDigit;
    build(idx + 1, min(mn, bestDigit), max(mx, bestDigit), greaterL || (bestDigit > l[idx]), lessR || (bestDigit < r[idx]));
}
int32_t main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        int a,b;
        cin>>a>>b;
        if(len(a) < len(b)){
            cout<<len(a).second-1<<'\n';
            continue;
        }
        n = len(a).first; 
        l = toVec(a), r = toVec(b);
        build(0, 9, 0, 0, 0); 
        cout<<'\n';
    }
    return 0;
}