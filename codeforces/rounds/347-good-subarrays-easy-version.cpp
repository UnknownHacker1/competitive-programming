/*
 * Good Subarrays (Easy Version)  [1736C1]
 * Problem:  https://codeforces.com/problemset/problem/1736/C1
 * Verdict:  ACCEPTED        Solved: 2022-10-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 1600 KB
 * Tags:     binary search, data structures, schedules, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1736/submission/175456093
 */

/*
ID: BidoTeima
LANG: C++11
TASK: 1736A
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
    ACPLS("");
tc{
    int n;
    cin>>n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    int t[n+1]={0};
    for(int i = 0; i <= n; i++)t[i]=n+1;
    ll ans = 0;
    for(int l = n; l >= 1; l--){
        t[max(0,l-a[l])]=l;
        if(l<n)t[l]=min(t[l],t[l+1]);
        ans += t[l] - l;
    }
    cout<<ans<<'\n';
}
}