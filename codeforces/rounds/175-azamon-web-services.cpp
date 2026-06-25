/*
 * Azamon Web Services  [1281B]
 * Problem:  https://codeforces.com/problemset/problem/1281/B
 * Verdict:  ACCEPTED        Solved: 2021-11-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 1200 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1281/submission/134999264
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
    string s,c;
    cin>>s>>c;
    if(s<c){
        cout<<s<<'\n';
        continue;
    }
    string b=s;
    sort(all(b));
    int x=(int)s.size();
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i]!=b[i]){
            x=i;
            break;
        }
    }
    if(x==(int)s.size()){
        cout<<"---\n";
        continue;
    }
    string mn=s;
    for(int i = 0; i < (int)s.size(); i++){
        if(i==x)continue;
        swap(s[i],s[x]);
        mn=min(mn,s);
        swap(s[i],s[x]);
    }
    if(mn<c){
        cout<<mn<<'\n';
    } else cout<<"---\n";
}
}
