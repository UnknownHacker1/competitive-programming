/*
 * Modular Multiplicative Inverse  [modinv]
 * Problem:  https://dmoj.ca/problem/modinv
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-11-19
 * Language: C++20
 * Runtime:  0.1685422 s     Memory: 3336.0 KB
 * Source:   https://dmoj.ca/src/5045290
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
uint64_t extendedGCD(uint64_t a, uint64_t b, uint64_t& x, uint64_t& y){
    if(!a){
        x=0;
        y=1;
        return b;
    }
    uint64_t x2,y2;
    uint64_t g = extendedGCD(b%a,a,x2,y2);
    x = y2 - b / a * x2;
    y = x2;
    return g;
}
int main()
{
    ACPLS();   
    uint64_t n,m;
    cin>>n>>m;
    uint64_t res,y;
    extendedGCD(n,m,res,y);
    cout<<(res+m)%m;
}