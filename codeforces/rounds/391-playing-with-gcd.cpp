/*
 * Playing with GCD  [1736B]
 * Problem:  https://codeforces.com/problemset/problem/1736/B
 * Verdict:  ACCEPTED        Solved: 2022-10-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 800 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1736/submission/175456152
 */

/*
ID: BidoTeima
LANG: C++11
TASK: 1736A
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

int main()
{
    ACPLS("");
tc{
    int n;
    cin>>n;
    int a[n];
    for(int&i:a)cin>>i;
    int b[n+1];
    b[0] = a[0];
    for(int i = 1; i < n; i++){
        b[i] = a[i]/__gcd(a[i],a[i-1])*a[i-1];
    }
    b[n] = a[n-1];
    bool ok = 1;
    for(int i = 0; i < n; i++){
        ok &= a[i] == __gcd(b[i],b[i+1]);
    }
    cout<<(ok?"YES\n":"NO\n");
}
}