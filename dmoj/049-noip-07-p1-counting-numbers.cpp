/*
 * NOIP '07 P1 - Counting Numbers  [noip07p1]
 * Problem:  https://dmoj.ca/problem/noip07p1
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2023-01-08
 * Language: C++20
 * Runtime:  0.120052438 s     Memory: 3860.0 KB
 * Source:   https://dmoj.ca/src/5197402
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    map<int,int>freq{};
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    for(auto&i:freq){
        cout<<i.first<<' '<<i.second<<'\n';
    }
}