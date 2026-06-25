/*
 * LCS on Permutations  [102951C]
 * Problem:  Gym/ICPC contest 102951 - problem C
 * Verdict:  ACCEPTED        Solved: 2022-04-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 1500 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/102951/submission/154230589
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
ll f(ll x){
    return ll((sqrt(8*x+1)-1.0)/2);
}
int main()
{
    ACPLS(); 
    int n;
    cin>>n;
    int pos[n+1];
    for(int i = 1; i <= n; i++){
        int x;cin>>x;pos[x]=i;
    }
    vector<int>ans;
    for(int i = 1; i <= n; i++){
        int x;cin>>x;
        auto it = lower_bound(ans.begin(),ans.end(),x,[&](int i1,int i2){
            return pos[i1]<pos[i2];
        });
        if(it==ans.end()){
            ans.push_back(x);
        }else *it=x;
    }
    cout<<ans.size();
}