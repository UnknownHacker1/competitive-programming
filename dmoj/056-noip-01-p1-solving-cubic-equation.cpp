/*
 * NOIP '01 P1: Solving Cubic Equation  [noip01p1]
 * Problem:  https://dmoj.ca/problem/noip01p1
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-12-08
 * Language: C++20
 * Runtime:  0.014628839 s     Memory: 3684.0 KB
 * Source:   https://dmoj.ca/src/5100416
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
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    int out = 0;
    for(double x = -100; x <= 100 && out < 3; x += 0.001){
        if( abs(a * x * x * x + b * x * x + c * x + d) < 1e-3){
            cout<<fixed<<setprecision(2)<<x<<' ';
            out++;
        }
    }
}