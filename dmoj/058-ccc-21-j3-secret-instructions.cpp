/*
 * CCC '21 J3 - Secret Instructions  [ccc21j3]
 * Problem:  https://dmoj.ca/problem/ccc21j3
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2022-01-07
 * Language: C++20
 * Runtime:  0.03039158 s     Memory: 3480.0 KB
 * Source:   https://dmoj.ca/src/4186382
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)99

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
int main()
{
    ACPLS();
    string prev;
    string str;
    while(cin>>str){
        if(str=="99999")break;
        int s=0,num=0;
        for(int j = 0; j < 5; j++){
            if(j<=1)
                s+=str[j]-'0';
            else
                num=num*10+str[j]-'0';
        }
        if(s&1)
            cout<<"left ",prev="left ";
        else if(s==0)
            cout<<prev;
        else
            cout<<"right ",prev="right ";
        cout<<num<<'\n';
    }
}