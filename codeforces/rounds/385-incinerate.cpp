/*
 * Incinerate  [1763B]
 * Problem:  https://codeforces.com/problemset/problem/1763/B
 * Verdict:  ACCEPTED        Solved: 2022-12-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  93 ms     Memory: 1200 KB
 * Tags:     binary search, brute force, data structures, implementation, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1763/submission/185972042
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
#ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
        freopen("input.txt", "r", stdin);
#endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/   

int main()
{
    ACPLS();  
tc{
    int n,k;
    cin>>n>>k; 
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i].first; 
    }
    for(int i = 0; i < n; i++){
        cin>>arr[i].second; 
    }
    sort(arr,arr+n);
    int min_suffix[n];
    min_suffix[n - 1] = arr[n - 1].second;
    for(int i = n - 2; i >= 0; i--){
        min_suffix[i] = min(min_suffix[i + 1], arr[i].second);
    }
    int cur_idx = 0;
    int total_damage = 0;
    bool trn = 0;
    while(k >= 0 && cur_idx < n){
        if(!trn){
            total_damage += k;
        }
        else{
            cur_idx = upper_bound(arr, arr+n, make_pair(total_damage, (int)1e9)) - arr;
            if(cur_idx == n)break;
            k -= min_suffix[cur_idx];
        }
        trn = !trn;
    }
    if(k >= 0)cout<<"YES\n";
    else cout<<"NO\n";
}
}