/*
 * Range and Partition  [1630B]
 * Problem:  https://codeforces.com/problemset/problem/1630/B
 * Verdict:  ACCEPTED        Solved: 2022-08-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  171 ms     Memory: 6800 KB
 * Tags:     binary search, constructive algorithms, data structures, greedy, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1630/submission/169980391
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename t1>
using ordered_set = tree<t1, null_type,less<t1>, rb_tree_tag,tree_order_statistics_node_update>;
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
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
    int n,k;
    cin>>n>>k;
    int a[n];
    int p[n+1]={0};
    for(int&i:a){
        cin>>i;
        p[i]++;
    }
    for(int i = 2; i <= n; i++){
        p[i]+=p[i-1];
    }
    int lo = 1, hi = n;
    vector<pair<int,int>>v;
    v.push_back({1,n});
    for(int i = 0; i < k-1; i++){
        v.push_back({i,i});        
    }
    v.push_back({k-1,n-1});
    while(lo <= hi){
        int m = (lo + hi) / 2;
        int x = -1, y = -1;
        for(int i = m; i <= n; i++){
            if(x == -1 || p[i] - p[i - m] > p[y] - p[x - 1]){
                x = i - m + 1, y = i;
            }
        }
        vector<pair<int,int>>cur;
        cur.push_back({x,y});
        int cnt = k - 1;
        int prevr = 0, cntxy = 0, cntother = 0;
        for(int i = 0; cnt && i < n - cnt; i++){
            if(x <= a[i] && a[i] <= y){
                cntxy++;
            }
            else cntother++;
            if(cntxy > cntother){
                cur.push_back({prevr,i});
                prevr = i + 1;
                cntxy = 0;
                cntother = 0;
                cnt--;
            }
        }
        cntxy = 0, cntother = 0;
        for(int i = prevr; i < n; i++){
            if(x <= a[i] && a[i] <= y){
                cntxy++;
            }
            else cntother++;
        }
        if(cntxy > cntother){
            cur.push_back({prevr, n-1});
        }
        if(cur.size() == k + 1){
            v = cur;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    --v[0].first,--v[0].second;
    for(auto p : v)
        cout<<p.first + 1<<' '<<p.second + 1<<'\n';
}
}   