/*
 * 3SUM Closure  [1698C]
 * Problem:  https://codeforces.com/problemset/problem/1698/C
 * Verdict:  ACCEPTED        Solved: 2022-06-28
 * Language: C++20 (GCC 11-64)
 * Runtime:  93 ms     Memory: 14200 KB
 * Tags:     brute force, data structures
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1698/submission/162090605
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
    ll a[n];
    map<ll,ll>freq{};
    for(auto&i:a)cin>>i,freq[i]++;
    if(n<=10){
        bool ansexist=1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(!freq[a[i]+a[j]+a[k]]){
                        ansexist=0;
                        break;
                    }
                }
            }
        }
        cout<<(ansexist?"YES\n":"NO\n");
        continue;
    }
    int neg=0,pos=0;
    for(int i = 0; i < n; i++){
        if(a[i]<0)neg++;
        if(a[i]>0)pos++;
    }
    if(pos>=2||neg>=2){
        cout<<"NO\n";
        continue;
    }
    vector<int>v;
    bool zeroexist=0;
    for(int i = 0; i < n; i++){
        if(a[i]<0)v.push_back(a[i]);
        if(a[i]==0&&zeroexist==0){
            v.push_back(0);
            zeroexist=1;
        }
        if(a[i]>0)v.push_back(a[i]);
    }
    bool ok = 1;
    for(int i = 0; i < (int)v.size(); i++){
        for(int j = i+1; j < (int)v.size(); j++){
            for(int k = j+1; k < (int)v.size(); k++){
                if(!freq[v[i]+v[j]+v[k]]){
                    ok=0;
                    break;
                }
            }
        }
    }
    cout<<(ok?"YES\n":"NO\n");
}
}