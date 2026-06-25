/*
 * Compression  [1107D]
 * Problem:  https://codeforces.com/problemset/problem/1107/D
 * Verdict:  ACCEPTED        Solved: 2022-07-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  498 ms     Memory: 145800 KB
 * Tags:     dp, implementation, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1107/submission/164615407
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
    int n;
    cin>>n;
    string lol[n+1];
    vector<int>div;
    for(int i = 0; i < n; i++){
        if(n%(i+1)==0)div.push_back(i+1);
        for(int j = 1; j <= n/4; j++){
            char ch;
            cin>>ch;
            if(isupper(ch)){
                lol[i]+=bitset<4>(ch-'A'+10).to_string();
            }
            else lol[i]+=bitset<4>(ch-'0').to_string();
        }
    }
    vector<vector<int>>pref(n+1,vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j]=pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1]+lol[i-1][j-1]-'0';
        }
    } 
    auto getsum = [&](int r1, int r2, int c1, int c2){
        return pref[r2][c2] - pref[r2][c1] - pref[r1][c2] + pref[r1][c1];
    };
    for(int bruh = (int)div.size()-1; bruh >= 0; bruh--){
        int x = div[bruh];
        bool ok = 1;
        for(int i = 0; i < n; i+=x){
            for(int j = 0; j < n; j+=x){
                ok&=(getsum(i,i+x,j,j+x))%(x*x)==0;
                if(!ok)break;
            }
            if(!ok)break;
        }
        if(ok){
            cout<<x;
            break;
        }
    }
}