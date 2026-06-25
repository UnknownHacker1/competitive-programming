/*
 * Pinkie Pie Eats Patty-cakes  [1393C]
 * Problem:  https://codeforces.com/problemset/problem/1393/C
 * Verdict:  ACCEPTED        Solved: 2021-12-21
 * Language: C++20 (GCC 11-64)
 * Runtime:  296 ms     Memory: 6000 KB
 * Tags:     constructive algorithms, greedy, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1393/submission/140189961
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
int main()
{
    ACPLS();
tc{
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    int lo = 0, hi = n;
    while(hi-lo>1){
        int mid = (lo+hi)/2;
        set<pair<int,int>,greater<pair<int,int>>>st;
        int freq[n+1]={0};
        for(int i:a)freq[i]++;
        for(int i = 1; i <= n; i++){
            if(freq[i])
                st.insert({freq[i],i});
        }
        vector<int>b;
        bool ok = 1;
        for(int i = 0; i < n; i++){
            if(i>=mid&&freq[b[i-mid]]){
                st.insert({freq[b[i-mid]],b[i-mid]});
            }
            if(st.empty()){
                ok = 0;
                break;
            }
            b.push_back(st.begin()->second);
            --freq[b.back()];
            st.erase(st.begin());
        }
        if(ok)lo=mid;
        else hi=mid;
    }
    cout<<lo-1<<'\n';
}
}