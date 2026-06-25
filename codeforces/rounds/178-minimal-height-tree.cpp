/*
 * Minimal Height Tree  [1437D]
 * Problem:  https://codeforces.com/problemset/problem/1437/D
 * Verdict:  ACCEPTED        Solved: 2022-01-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 2900 KB
 * Tags:     graphs, greedy, shortest paths, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1437/submission/142107591
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
    vector<int>v;
    v.push_back(1);
    for(int i = 1; i < n;){
        int start=i;
        int cnt=0;
        while((a[i]>a[i-1]&&i<n)||(i==start)){
            i++;
            cnt++;
        }
        v.push_back(cnt);
    }
    int ans=0;
    int prev=0;
    for(int i = 0; i < (int)v.size();){
        int newprev=i+1;
        bool lol=(i==(int)v.size()-1);
        for(int k = prev; k<newprev; k++){
            i+=v[k];
        }
        prev=newprev; 
        if(!lol)ans++;
    }
    cout<<ans<<'\n';
}
}
 
