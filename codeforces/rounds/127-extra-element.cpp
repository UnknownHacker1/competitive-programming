/*
 * Extra Element  [1185D]
 * Problem:  https://codeforces.com/problemset/problem/1185/D
 * Verdict:  ACCEPTED        Solved: 2025-03-25
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  264 ms     Memory: 7900 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1185/submission/312332760
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int n;
    cin>>n;
    int a[n];
    map<int,int>idx;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        idx[a[i]]=i+1;
    }
    sort(a,a+n);
    bool okp[n]{},oks[n]{};
    okp[0]=1;
    for(int i = 1; i < n; i++){
        okp[i]=(i==1?1:a[i]-a[i-1]==a[i-1]-a[i-2])&&okp[i-1];  
    }
    oks[n-1]=1;
    for(int i = n - 2; i >= 0; i--){
        oks[i]=(i==n-2?1:a[i+1]-a[i]==a[i+2]-a[i+1])&&oks[i+1];
    }
    if(okp[n-2]){
        cout<<idx[a[n-1]];
        return 0;
    }
    if(oks[1]){
        cout<<idx[a[0]];
        return 0;
    }
    for(int i = 1; i + 1 < n; i++){
        if(okp[i - 1] && oks[i + 1] && (i==1?1:a[i + 1] - a[i - 1] == a[i-1]-a[i-2]) && (i==n-2 ? 1 : a[i + 1] - a[i - 1] == a[i + 2] - a[i + 1] ) ){
            cout<<idx[a[i]];
            return 0;
        }
    } 
    cout<<-1;
    return 0;
}