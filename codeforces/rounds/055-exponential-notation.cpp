/*
 * Exponential notation  [691C]
 * Problem:  https://codeforces.com/problemset/problem/691/C
 * Verdict:  ACCEPTED        Solved: 2022-09-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 4900 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/691/submission/170971582
 */

/// isA AC
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
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
int main()
{
    ACPLS("");  
    string s;
    cin>>s;
    int i = 0; 
    while(s[i]=='0')i++;
    s=string(s.begin()+i,s.end());
    int pos = (int)s.size();
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i]=='.')pos=i;
    }
    int swapwith = -1;
    bool available = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i]=='.')available=1;
        if(s[i] != '.' && s[i] != '0'){
            swapwith = i + 1;
            break;
        }
    }
    if(swapwith == -1){
        cout<<0;
        return 0;
    }
    string res;
    i=swapwith-1;
    if(s[i] != '.'){
        res.push_back(s[i]);
        i++;
    }
    else{
        res.push_back(s[i+1]);
        i += 2;
    }
    for(; i < swapwith; i++){
        if(s[i]!='.')res.push_back(s[i]);
    }
    if(i<(int)s.size())res.push_back('.');
    for(; i<(int)s.size(); i++){
        if(s[i]!='.')res.push_back(s[i]);
    }
    while(res.back()=='0')res.pop_back();
    if(res.back()=='.')res.pop_back();
    cout<<res;
    if(pos-swapwith+available != 0){
        cout<<'E';
        cout<<pos-swapwith+available;
    } 
}   