/*
 * Absolute Maximization  [1763A]
 * Problem:  https://codeforces.com/problemset/problem/1763/A
 * Verdict:  ACCEPTED        Solved: 2022-12-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     bitmasks, constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1763/submission/185963948
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

int main()
{
    ACPLS();  
tc{
    int n;
    cin>>n;
    int a[n];
    int mx = 0;
    int has0[32]={0};
    int mn = 1e9;
    for(auto&i:a){
        cin>>i,mx|=i;
        mn = min(mn, i);
        for(int j = 0; j < 16; j++){
            if(!(i & (1<<j))) has0[j] = 1;
        }
    }
    for(int i = 0; i < 16; i++){
        if( (mn & (1 << i)) && has0[i] == 1 ){
            mn -= (1 << i);
        }
    }
    cout<<mx-mn<<'\n';
}
}