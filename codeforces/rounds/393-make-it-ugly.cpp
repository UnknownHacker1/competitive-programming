/*
 * Make It Ugly  [1954B]
 * Problem:  https://codeforces.com/problemset/problem/1954/B
 * Verdict:  ACCEPTED        Solved: 2025-03-18
 * Language: C++17 (GCC 7-32)
 * Runtime:  109 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1954/submission/311332030
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        set<int>st;
        for(auto&i:a)cin>>i,st.insert(i);
        if(st.size()==1){
            cout<<"-1\n";
            continue;
        }
        int r[n+1];
        memset(r,-1,sizeof(r));
        int ans = 2;
        for(int i = 0; i + 1 < n; i++){
            if(r[a[i]] != -1){ 
                ans = max(ans, r[a[i]] - i + 1);
            }else{
                int j = n - 1;
                while(j>i&&a[i]==a[j])--j;
                r[a[i]]=j;
                ans = max(ans, j - i + 1);
            }
            if(i+2<n&&a[i]!=a[i+1]&&a[i]!=a[i+2])ans=max(ans,n-i);
        }
        for(int i = n - 1; i - 2 >= 0; i--){
            if(a[i] != a[i - 1] && a[i] != a[i - 2])ans=max(ans,i+1);
        }
        int mn = n-ans;
        vector<int>v;
        for(int i = 0; i < n; i++){
            if(a[i]!=a[0])v.push_back(i);
        }
        for(int i = 1; i < (int)v.size(); i++){
            mn=min(mn,v[i]-v[i-1]-1);
        }
        cout<<mn<<'\n';
    }
    return 0;
}