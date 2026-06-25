/*
 * Meximum Array  [1629C]
 * Problem:  https://codeforces.com/problemset/problem/1629/C
 * Verdict:  ACCEPTED        Solved: 2022-01-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  140 ms     Memory: 12100 KB
 * Tags:     constructive algorithms, data structures, greedy, math, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1629/submission/143722052
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
void init(int n, set<int>&st){
    for(int i = 0; i <= n; i++)
        st.insert(i);
}
int main()
{
    ACPLS();   
tc{
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    set<int>st;
    init(n,st);
    int mexsuff[n];
    for(int i = n-1; i >= 0; i--){
        if(st.find(a[i])!=st.end())
            st.erase(a[i]);
        mexsuff[i]=*st.begin();
    } 
    int start = 0;
    vector<int>ans;
    init(n,st);
    while(start<n){
        int reset=start;
        int mex=mexsuff[start];
        for(start;(*st.begin()) != mex;start++){
            if(st.find(a[start])!=st.end())
                st.erase(a[start]);
        }
        for(int i = reset; i < start; i++){
            st.insert(a[i]);
        }
        ans.push_back(mex);
        if(start==reset)start++;
    }
    cout<<ans.size()<<'\n';
    for(int i:ans)
        cout<<i<<' ';
    cout<<'\n';
}
}