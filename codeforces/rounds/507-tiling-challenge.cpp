/*
 * Tiling Challenge  [1150B]
 * Problem:  https://codeforces.com/problemset/problem/1150/B
 * Verdict:  ACCEPTED        Solved: 2022-07-18
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1150/submission/164820472
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
bool check(vector<string>&s,vector<vector<bool>>&marked,int i, int j){
    bool ret = (!marked[i+1][j-1]) && (!marked[i+1][j]) && (!marked[i+1][j+1]) &&\
               (!marked[i+2][j]) && s[i+1][j-1]=='.' && s[i+1][j]=='.' && s[i+1][j+1]=='.'&&\
               s[i+2][j]=='.';
    marked[i][j]=marked[i+1][j-1]=marked[i+1][j]=marked[i+1][j+1]=marked[i+2][j]=1;
    return ret;
}
int main()
{
    ACPLS();   
    int n;
    cin>>n;
    vector<string>s(n);
    for(string&str:s)cin>>str;
    vector<vector<bool>>marked(n,vector<bool>(n,0));
    bool ok = 1;
    for(int i = 0; i < n-2; i++){
        for(int j = 1; j < n-1; j++){
            if(s[i][j]=='.'&&!marked[i][j]){
                ok&=check(s,marked,i,j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j]=='.')ok&=marked[i][j];
        }
    }
    cout<<(ok?"YES":"NO");
}