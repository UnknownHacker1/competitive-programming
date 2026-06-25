/*
 * Make Even  [1611A]
 * Problem:  https://codeforces.com/problemset/problem/1611/A
 * Verdict:  ACCEPTED        Solved: 2021-11-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1611/submission/136844378
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
    string s;
    cin>>n;
    s=to_string(n);
    bool check=0;
    for(int i = 0; i < (int)s.size(); i++){
        if((s[i]-'0')%2==0){
            check=1;
            break;
        }
    }
    if(!check)
        cout<<"-1\n";
    else if(n%2==0){
        cout<<"0\n";
    }
    else if((s[0]-'0')%2==0){
        cout<<"1\n";
    }
    else
        cout<<"2\n";
}
}
