/*
 * Distinct Characters Queries  [1234D]
 * Problem:  https://codeforces.com/problemset/problem/1234/D
 * Verdict:  ACCEPTED        Solved: 2021-10-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  358 ms     Memory: 7100 KB
 * Tags:     data structures
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1234/submission/131560115
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
    string s;
    cin>>s;
    for(auto&i:s)
        i-='a';
    set<int>occ[26];
    for(int i = 0; i < (int)s.size(); i++){
        occ[s[i]].insert(i);
    }
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int pos;
            char c;
            cin>>pos>>c;
            c-='a';
            --pos;
            occ[s[pos]].erase(pos);
            s[pos]=c;
            occ[s[pos]].insert(pos);
        }
        else{
            int l,r;
            cin>>l>>r;
            --l,--r;
            int ans=0;
            for(int i = 0; i < 26; i++){
                if(occ[i].empty())
                    continue;
                auto it = occ[i].lower_bound(l);
                if(it==occ[i].end())
                    continue;
                if((*it)<=r)
                    ++ans;
            }
            cout<<ans<<'\n';
        }
    }
}