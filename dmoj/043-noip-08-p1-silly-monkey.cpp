/*
 * NOIP '08 P1 - Silly Monkey  [noip08p1]
 * Problem:  https://dmoj.ca/problem/noip08p1
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2023-01-09
 * Language: C++20
 * Runtime:  0.033558793 s     Memory: 3428.0 KB
 * Source:   https://dmoj.ca/src/5200982
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
    string s;
    cin>>s;
    int freq[26]={0};
    for(char ch : s)freq[ch - 'a']++;
    int mn = 1e9, mx = 0;
    for(char ch : s){
        mn = min(mn, freq[ch-'a']);
        mx = max(mx, freq[ch-'a']);
    }
    int d = (mx)-(mn);
    bool ok = d>1;
    for(int i = 2; i < d; i++){
        if(d % i == 0)ok = 0;
    } 
    if(ok){
        cout<<"Lucky Word\n"<<d<<'\n';
    }else{
        cout<<"No Answer\n0\n";
    }
}