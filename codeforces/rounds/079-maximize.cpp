/*
 * Maximize!  [939E]
 * Problem:  https://codeforces.com/problemset/problem/939/E
 * Verdict:  ACCEPTED        Solved: 2022-06-24
 * Language: C++20 (GCC 11-64)
 * Runtime:  436 ms     Memory: 7200 KB
 * Tags:     binary search, greedy, ternary search, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/939/submission/161651284
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
    int q;
    cin>>q;
    vector<ll>v;
    int l = 0;
    ll sum=0;
    cout<<fixed<<setprecision(6);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            sum+=x-(v.size()?v.back():0);
            v.push_back(x);
            if(v.empty())continue;
            while(l<(int)v.size()-1&&(sum+v[l])*(l+1) < sum*(l+2)){
                sum+=v[l++];
            }
        }
        else{
            cout<<v.back()-sum*1.0/(l+1)<<'\n';
        }
    }
}
