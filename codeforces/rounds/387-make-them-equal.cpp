/*
 * Make Them Equal  [1594C]
 * Problem:  https://codeforces.com/problemset/problem/1594/C
 * Verdict:  ACCEPTED        Solved: 2021-10-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3900 KB
 * Tags:     brute force, greedy, math, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1594/submission/131197114
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
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
tc{
    int n;
    char c;
    cin>>n>>c;
    char str[n+1];
    bool ans0=1;
    for(int i = 1; i <= n; i++)
        cin>>str[i],ans0&=str[i]==c;
    if(ans0){
        cout<<"0\n";
        continue;
    }
    int ans=-1;
    for(int x = 1; x <= n; x++){
        bool ok = 1;
        for(int i = x; i <= n; i+=x){
            ok&=str[i]==c;
        }
        if(ok){
            ans=x;
            break;
        }
    }
    if(ans!=-1){
        cout<<"1\n"<<ans<<'\n';
        continue;
    }
    cout<<"2\n"<<n<<' ';
    for(int i = 1; i <= n; i++){
        if(n%i!=0){
            cout<<i<<'\n';
            break;
        }
    }
}
}
