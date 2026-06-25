/*
 * Crazy Diamond  [1148C]
 * Problem:  https://codeforces.com/problemset/problem/1148/C
 * Verdict:  ACCEPTED        Solved: 2022-01-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  202 ms     Memory: 15700 KB
 * Tags:     constructive algorithms, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1148/submission/142171509
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
    int n;
    cin>>n;
    int pos[n+1],a[n+1];
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        a[i]=x;
        pos[x]=i;
    }
    vector<pair<int,int>>v;
    for(int x = 1; x <= n; x++){
        int i = min(x,pos[x]);
        int j = max(x,pos[x]);
        if(i==j)
            continue;
        if(2*(j-i)>=n){
            v.push_back({i,j}); 
        }
        else if(2*(n-i)>=n&&2*(j-1)>=n){
        v.push_back({i,n});
        v.push_back({1,n});
        v.push_back({1,j});
        v.push_back({1,n});
        v.push_back({i,n});
        }
        else if(2*i-2>=n){
            v.push_back({1,i});
            v.push_back({1,j});
            v.push_back({1,i});
        }
        else{
            v.push_back({n,i});
            v.push_back({n,j});
            v.push_back({n,i});
        }
        swap(a[i],a[j]);
        pos[a[i]]=i;
        pos[a[j]]=j;
    }
    cout<<(int)v.size()<<'\n';
    for(auto i:v)
        cout<<i.first<<' '<<i.second<<'\n';
}
 
