/*
 * Make it Divisible by 25  [1593B]
 * Problem:  https://codeforces.com/problemset/problem/1593/B
 * Verdict:  ACCEPTED        Solved: 2021-10-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     dfs and similar, dp, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1593/submission/131766969
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
    string s;
    cin>>s;
    int ans = (int)s.size();
    int cnt=0;
    int zerocnt=0;
    for(int i = (int)s.size()-1; i >= 0; i--){
        if(zerocnt==2)break;
        if(s[i]=='0')++zerocnt;
        else ++cnt;
    }
    ans=min(ans,cnt);
    cnt=0;
    bool five=0,two=0;
    for(int i = (int)s.size()-1; i >= 0; i--){
        if(five&&two)
            break;
        if(s[i]=='5'){
            if(five==0){
                five=1;
            }
            else ++cnt;
        }
        else if(s[i]=='2'){
            if(five==1){
                two=1;
            }
            else ++cnt;
        }
        else ++cnt;
    }
    ans=min(ans,cnt);
    cnt=0;
    bool zero=0;
    five=0;
    for(int i = (int)s.size()-1; i >= 0; i--){
        if(five&&zero)
            break;
        if(s[i]=='0'){
            if(zero==0){
                zero=1;
            }
            else ++cnt;
        }
        else if(s[i]=='5'){
            if(zero==1){
                five=1;
            }
            else ++cnt;
        }
        else ++cnt;
    }
    ans=min(ans,cnt);
    cnt=0;
    bool seven=0;
    five=0;
    for(int i = (int)s.size()-1; i >= 0; i--){
        if(five&&seven)
            break;
        if(s[i]=='5'){
            if(five==0){
                five=1;
            }
            else ++cnt;
        }
        else if(s[i]=='7'){
            if(five==1){
                seven=1;
            }
            else ++cnt;
        }
        else ++cnt;
    }
    ans=min(ans,cnt);
    cout<<ans<<'\n';
}
}