/*
 * Guess the Array  [727C]
 * Problem:  https://codeforces.com/problemset/problem/727/C
 * Verdict:  ACCEPTED        Solved: 2021-09-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 3700 KB
 * Tags:     constructive algorithms, interactive, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/727/submission/129684753
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,int>,null_type,less<pair<long long,int>>,rb_tree_tag,tree_order_statistics_node_update>
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
int ask(int i, int j){
    cout<<"? "<<i<<' '<<j<<endl;
    int ret;
    cin>>ret;
    return ret;
}
int main()
{
    ACPLS();
    int n;
    cin>>n;
    int ans[n+1];
    int a=ask(1,2);
    int b=ask(2,3);
    int c=ask(1,3);
    ans[3]=(b+c-a)/2;
    ans[2]=b-ans[3];
    ans[1]=a-ans[2];
    for(int i = 4; i <= n; i++){
        ans[i]=ask(i,i-1)-ans[i-1];
    }
    cout<<"! ";
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}