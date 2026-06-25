/*
 * Color the Fence  [349B]
 * Problem:  https://codeforces.com/problemset/problem/349/B
 * Verdict:  ACCEPTED        Solved: 2022-04-01
 * Language: C++17 (GCC 9-64)
 * Runtime:  30 ms     Memory: 3900 KB
 * Tags:     data structures, dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/349/submission/152281886
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
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
    int v;
    cin>>v;
    int a[10]; 
    for(int i = 1; i <= 9; i++)cin>>a[i];
    int idx=min_element(a+1,a+10)-a;
    string ans;
    for(int i = 1; i <= v/a[idx]; i++){
        ans.push_back(idx+'0');
    }
    v%=a[idx];
    for(int i = 0; i < (int)ans.size(); i++){
        for(int j = 9; j > ans[i]-'0'; j--){
            if(v+a[ans[i]-'0']>=a[j]){
                v+=a[ans[i]-'0']-a[j];
                ans[i]=j+'0';
                break;
            }
        }
    }
    cout<<ans;
    if(ans.empty())cout<<-1;
}