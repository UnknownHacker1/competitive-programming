/*
 * Escape from Stones  [265C]
 * Problem:  https://codeforces.com/problemset/problem/265/C
 * Verdict:  ACCEPTED        Solved: 2023-08-07
 * Language: C++20 (GCC 11-64)
 * Runtime:  233 ms     Memory: 6300 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/265/submission/217772839
 */

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = (int)s.size();
    int l = 0, r = n - 1;
    int a[n];
    for(int i = 0; i < n; i++){
        if(s[i]=='l')a[r--]=i;
        else a[l++]=i;
    }
    for(int p : a)
        cout<<p+1<<'\n';
    return 0;
}