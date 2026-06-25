/*
 * NOIP/CSP '19 P1 - Gray Code  [noip19p1]
 * Problem:  https://dmoj.ca/problem/noip19p1
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-12-28
 * Language: C++20
 * Runtime:  0.064662283 s     Memory: 3444.0 KB
 * Source:   https://dmoj.ca/src/5163004
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
uint64_t pw2(ll i){
    uint64_t ret = 1;
    while(i--)ret*=2;
    return ret;
}
string rec(uint64_t n, uint64_t k){
    if(n == 1){
        return k?string("1"):string("0");
    }
    if(k < pw2(n-1) ){
        return string("0")+rec(n-1,k);
    }
    return string("1")+rec(n-1,pw2(n-1) - 1 - k + pw2(n-1));
}
int main()
{
    ACPLS();  
    uint64_t n,k;
    cin>>n>>k;
    cout<<rec(n,k);
}