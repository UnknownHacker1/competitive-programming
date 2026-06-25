/*
 * Mainak and Array  [1726A]
 * Problem:  https://codeforces.com/problemset/problem/1726/A
 * Verdict:  ACCEPTED        Solved: 2022-09-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1726/submission/171072329
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
tc{
    int n;
    cin>>n;
    int a[n];
    for(int&i:a)cin>>i;
    if(n == 1){
        cout<<"0\n";
        continue;
    }
    int mx = *max_element(a+1,a+n);
    int mn = *min_element(a,a+n-1);
    int ans = max(mx-a[0],a[n-1]-mn);
    for(int i = 0; i + 1 < n; i++){
        ans = max(ans, a[i] - a[i + 1]);
    }
    cout<<ans<<'\n';
}
}   