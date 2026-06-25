/*
 * IOI '05 P3 - Mean Sequence  [ioi05p3]
 * Problem:  https://dmoj.ca/problem/ioi05p3
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2023-03-13
 * Language: C++20
 * Runtime:  1.985463826 s     Memory: 3452.0 KB
 * Source:   https://dmoj.ca/src/5407375
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
    if(str.size() && str != "IIOT")
        moo(str);
    else if(str != "IIOT"){
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
#define tcccc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/
int main()
{  
    ACPLS("");
    int n;
    cin>>n; 
    ll sumodd = 0, sumeven = 0, mn = -2e9, mx = 2e9;
    for(int i = 0; i < n; i++){
        ll m;
        cin>>m;
        if(i%2==0)sumeven+=m;
        else sumodd+=m;
        if(!i){
            mx = min(mx, m);
            continue;
        }
        ll x = 2 * (sumeven - sumodd);
        if(i & 1){
            x *= -1;
            // x >= m[i] 
            // x + s >= m[i]
            // s >= m[i] - x
            mn = max(mn, m - x);
        }
        else{
            // x >= m[i]
            // x - s >= m[i]
            // x >= m[i] + s
            // x - m[i] >= s
            mx = min(mx, x - m);
        }
    }
    cout<<max(mx-mn+1,0ll)<<'\n';
}