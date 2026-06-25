/*
 * Kevin and Permutation  [1754B]
 * Problem:  https://codeforces.com/problemset/problem/1754/B
 * Verdict:  ACCEPTED        Solved: 2022-10-23
 * Language: C++20 (GCC 11-64)
 * Runtime:  0 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1754/submission/177672300
 */

/*
ID: BidoTeima
LANG: C++11
TASK: Izbori
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
    for(int i = 1; i <= n/2; i++){
        cout<<i+n/2<<' '<<i<<' ';
    }
    if(n&1){
        cout<<n; 
    }
    cout<<'\n';
}
}