/*
 * Square-Free Division (easy version)  [1497E1]
 * Problem:  https://codeforces.com/problemset/problem/1497/E1
 * Verdict:  ACCEPTED        Solved: 2021-11-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  795 ms     Memory: 49400 KB
 * Tags:     data structures, dp, greedy, math, number theory, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1497/submission/135990603
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
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
int lp[(int)1e7+5];
void sieve(int n){
    ++n;
    for(int i = 2; i * i <= n; i++){
        for(int j = i * i; j <= n; j+=i){
            if(lp[j]==0)
                lp[j]=i;
        }
    }
}
int main()
{
    ACPLS();
    sieve(1e7);
tc{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(auto&i:a)cin>>i;
    for(int i = 0; i < n; i++){
        map<int,int>fact;
        while(lp[a[i]]!=0){
            //cout<<lp[a[i]]<<' ';
            ++fact[lp[a[i]]];
            a[i]/=lp[a[i]];
        }
        //cout<<a[i];
        ++fact[a[i]];
        int x = 1;
        for(auto&elem:fact){
            // cout<<elem.first<<' '<<elem.second<<'\n';
            if(elem.second%2==1){
                x*=elem.first;
            }
        }
        a[i]=x;
        //cout<<'\n';
    }
    int ans=1;
    map<int,bool>freq{};
    for(int i = 0; i < n; i++){
        //cout<<a[i]<<' ';
        if(freq[a[i]]){
            freq.clear();
            ++ans;
        }
        freq[a[i]]=1;
    }
    //cout<<'\n';
    cout<<ans<<'\n';
}
}