/*
 * Distance  [1612A]
 * Problem:  https://codeforces.com/problemset/problem/1612/A
 * Verdict:  ACCEPTED        Solved: 2021-11-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1612/submission/136522309
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
int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}
int main()
{
    ACPLS(); 
tc{
    int x,y;
    cin>>x>>y;
    if((x+y)&1){
        cout<<"-1 -1\n";
        continue;
    }
    int req=(x+y)>>1;
    pair<int,int>ans={-1,-1};
    for(int x1 = 0; x1 <= 50; x1++){
        for(int y1 = 0; y1 <= 50; y1++){
            if(dist(0,0,x1,y1)==req&&dist(x,y,x1,y1)==req){
                ans={x1,y1};
                break;
            }
        }
    }
    cout<<ans.first<<' '<<ans.second<<'\n';
}
}
