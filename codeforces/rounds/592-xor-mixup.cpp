/*
 * XOR Mixup  [1698A]
 * Problem:  https://codeforces.com/problemset/problem/1698/A
 * Verdict:  ACCEPTED        Solved: 2022-06-28
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     bitmasks, brute force
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1698/submission/162060177
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
    int a[n];
    int tot=0;
    for(auto&i:a)cin>>i,tot^=i;
    int ans=-1;
    for(int i = 0; i < n; i++){
        if(tot^a[i]==a[i]){
            ans=a[i];
            break;
        }
    }
    cout<<ans<<'\n';
}
}