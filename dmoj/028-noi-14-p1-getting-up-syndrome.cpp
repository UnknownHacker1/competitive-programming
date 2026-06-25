/*
 * NOI '14 P1 - Getting-Up Syndrome  [noi14p1]
 * Problem:  https://dmoj.ca/problem/noi14p1
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-04-08
 * Language: C++20
 * Runtime:  0.596157661 s     Memory: 7392.0 KB
 * Source:   https://dmoj.ca/src/5460485
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
pair<string,int> a[(int)1e5 + 3];
int n;
int bit(int x, int i){
    return (x >> i) & 1;
}
bool f(bool b, int j){
    for(int i = 0; i < n; i++){
        if(a[i].first=="AND"){
            b = b & bit(a[i].second, j);
        } else if(a[i].first=="XOR"){
            b = b ^ bit(a[i].second, j);
        } else{
            b = b | bit(a[i].second, j);
        }
    }    
    return b;
}
int main()
{    
    //ACPLS("");   
    int m;
    cin>>n>>m; 
    for(int i = 0; i < n; i++)cin>>a[i].first>>a[i].second;
    int ans = 0;
    for(int j = 29; j >= 0; j--){
        // try having this bit in our answer 
        // see if it is possible to have it by setting it to 0 
        if(f(0, j)){
            ans |= (1 << j);
            continue;
        }
        if(f(1, j) && m >= (1 << j)){
            m -= (1 << j);
            ans |= (1 << j);
            continue;
        }
    } 
    cout<<ans;
    return 0;
}