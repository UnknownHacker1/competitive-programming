/*
 * String Deletion  [1430D]
 * Problem:  https://codeforces.com/problemset/problem/1430/D
 * Verdict:  ACCEPTED        Solved: 2022-05-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 2500 KB
 * Tags:     binary search, data structures, greedy, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1430/submission/156139056
 */

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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
int main()
{
    ACPLS();
tc{
    int n;
    string s;
    cin>>n>>s;
    vector<int>g;
    int cnt=1;
    for(int i = 1; i < n; i++){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            g.push_back(cnt);
            cnt=1;
        }
    }
    g.push_back(cnt);
    int l=0,cur=0;
    while(cur<(int)g.size()&&g[cur]==1){
        cur++;
    }
    int del=0,ans=0;
    while(l<(int)g.size()&&cur<(int)g.size()&&del<n){
        --g[cur];
        del+=g[l]+1;
        ++l; 
        while(cur<(int)g.size()&&(cur<l||g[cur]==1))cur++;
        ++ans;
    }
    cout<<ans+(n-del+1)/2<<'\n';
}
}