/*
 * CCC '21 S2 - Modern Art  [ccc21s2]
 * Problem:  https://dmoj.ca/problem/ccc21s2
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-01-07
 * Language: C++20
 * Runtime:  0.429082867 s     Memory: 15048.0 KB
 * Source:   https://dmoj.ca/src/4186539
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
    while (tttttt--)

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
int main()
{
    ACPLS();
    int n,m;
    cin>>m>>n;
    int row[m]={0},col[n]={0};
    int rowlst[m]={0},collst[n]={0};
    memset(rowlst,-1,sizeof(rowlst));
    memset(collst,-1,sizeof(collst));
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        char ch;
        int num;
        cin>>ch>>num;
        if(ch=='R')row[num-1]++,rowlst[num-1]=i;
        else col[num-1]++,collst[num-1]=i;
    }
    int ans=0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ans+=(row[i]+col[j])&1;
        }
    }
    cout<<ans;
}