/*
 * NOIP '08 P2 - Expression by Matches  [noip08p2]
 * Problem:  https://dmoj.ca/problem/noip08p2
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-01-09
 * Language: C++20
 * Runtime:  3.566015981 s     Memory: 3424.0 KB
 * Source:   https://dmoj.ca/src/5200994
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
int matchsticks[10]={
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};
int f(int x){
    int ret = 0;
    do{
        ret += matchsticks[x%10];
        x/=10;
    }while(x);
    return ret;
}
int req(int a, int b, int c){
    return f(a) + f(b) + f(c) + 4;
}
int main()
{ 
    ACPLS();    
    int n;
    cin>>n;
    int ans = 0;
    for(int A = 0; A <= 5000; A++){
        for(int B = 0; B <= 5000; B++){
            int C = A + B;
            if(req(A, B, C) == n){
                ans++;
            }
        }
    }
    cout<<ans;
}