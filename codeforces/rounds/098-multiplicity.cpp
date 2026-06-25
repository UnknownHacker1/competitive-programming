/*
 * Multiplicity  [1061C]
 * Problem:  https://codeforces.com/problemset/problem/1061/C
 * Verdict:  ACCEPTED        Solved: 2022-12-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  2120 ms     Memory: 218600 KB
 * Tags:     data structures, dp, implementation, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1061/submission/186777992
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
#ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
        freopen("input.txt", "r", stdin);
#endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/  
int n; 
int a[(int)1e5+3];
ll mod = 1e9 + 7;
vector<int>occurences[(int)1e5 + 3];
map<int,int>dp[(int)1e5+3]; 
int rec(int idx, int si){
    if(idx == n || si == n)
        return 1;
    auto& ref = dp[idx][si];
    if(ref)return ref;
    auto it = upper_bound(occurences[si].begin(),occurences[si].end(), idx);
    auto it2 = upper_bound(occurences[si + 1].begin(), occurences[si + 1].end(), idx);
    ll ret = 1;
    if(it != occurences[si].end()){
        ret += rec(*it, si);
        if(ret >= mod)ret -= mod;
    }
    if(it2 != occurences[si + 1].end()){
        ret += rec(*it2, si + 1);
        if(ret >= mod)ret -= mod;
    }
    return ref = ret;

}
int main()
{
    ACPLS();  
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i]; 
        for(ll x = 1; x * x <= a[i]; x++){
            if(a[i] % x == 0){

                if(x <= n)occurences[x].push_back(i); 
                if(a[i] / x <= n && x * x != a[i]){ 
                    occurences[a[i] / x].push_back(i);
                }
            }
        } 
    }
    cout<<rec(0, 1);
}   