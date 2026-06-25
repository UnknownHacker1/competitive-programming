/*
 * Shoe Shuffling  [1691B]
 * Problem:  https://codeforces.com/problemset/problem/1691/B
 * Verdict:  ACCEPTED        Solved: 2022-05-31
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 10300 KB
 * Tags:     constructive algorithms, greedy, implementation, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1691/submission/159018060
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
    cin>>n;
    int s[n];
    for(auto&i:s)cin>>i; 
    map<int,vector<int>>occ{};
    int p[n+1];
    for(int i = 0; i < n; i++){
        p[i]=i+1;
    }
    for(int i = 0; i < n; i++){
        occ[s[i]].push_back(i);
    }
    for(auto&it:occ){
        vector<int>&v = it.second;
        for(int i = 0; i < (int)v.size()/2; i++){
            swap(p[v[i]],p[v[(int)v.size()-i-1]]);
        }
        if(v.size()&1){
            swap(p[v[(int)v.size()/2]],p[v[0]]);
        }
    }
    bool ok = 1;
    for(int i = 0; i < n; i++){
        if(p[i]==i+1){
            ok = 0;
            break;
        }
    }
    if(ok){
        for(int i = 0; i < n; i++){
            cout<<p[i]<<' ';
        }
        cout<<'\n';
    }
    else cout<<"-1\n";
}
}