/*
 * Cut and Paste  [1280A]
 * Problem:  https://codeforces.com/problemset/problem/1280/A
 * Verdict:  ACCEPTED        Solved: 2021-11-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  1560 ms     Memory: 5000 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1280/submission/136822896
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
ll mod = (ll)1e9+7;
int main()
{
    ACPLS(); 
tc{
    int x;
    string s;
    cin>>x>>s;
    ll totsize=(int)s.size();
    for(int i = 0; i < x; i++){
        if(s.size()>=x){
            totsize+=((totsize+mod-i-1)%mod*(s[i]-'0'-1)%mod)%mod;
            totsize%=mod;
            continue;
        }
        string c = string(s.begin()+i+1,s.end());
        for(int j = 0; j < s[i]-'0'-1; j++){
            s+=c;
            if(s.size()>=x)break;
        }
        totsize+=((totsize+mod-i-1)%mod*(s[i]-'0'-1)%mod)%mod;
        totsize%=mod;
    }
    cout<<totsize<<'\n';
}
}
