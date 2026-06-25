/*
 * Rectangles  [1028C]
 * Problem:  https://codeforces.com/problemset/problem/1028/C
 * Verdict:  ACCEPTED        Solved: 2021-11-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  187 ms     Memory: 4200 KB
 * Tags:     geometry, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1028/submission/136165654
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
    int n;
    cin>>n;
    int x1[n],y1[n],x2[n],y2[n];
    int x1c[n],y1c[n],x2c[n],y2c[n];
    for(int i = 0; i < n; i++){
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        x1c[i]=x1[i],y1c[i]=y1[i],
        x2c[i]=x2[i],y2c[i]=y2[i];
    }
    sort(x1c,x1c+n);
    sort(y1c,y1c+n);
    sort(x2c,x2c+n);
    sort(y2c,y2c+n);
    int ans1=-1,ans2=-1;
    for(int i = 0; i < n; i++){
       int rect[4];
       if(x1[i]==x1c[n-1]){
            rect[0]=x1c[n-2];
       }
       else rect[0]=x1c[n-1];
       if(y1[i]==y1c[n-1]){
            rect[1]=y1c[n-2];
       } 
       else rect[1]=y1c[n-1];
       if(x2[i]==x2c[0]){
            rect[2]=x2c[1];
       } else rect[2]=x2c[0];
       if(y2[i]==y2c[0]){
            rect[3]=y2c[1];
       }
       else rect[3]=y2c[0];
       //cout<<rect[0]<<' '<<rect[1]<<' '<<rect[2]<<' '<<rect[3]<<'\n';
       if(rect[0]<=rect[2]&&rect[1]<=rect[3]){
        ans1=rect[0],ans2=rect[1];
       }
    }
    cout<<ans1<<' '<<ans2<<'\n';
}
