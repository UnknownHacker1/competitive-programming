/*
 * Special Permutation  [1612B]
 * Problem:  https://codeforces.com/problemset/problem/1612/B
 * Verdict:  ACCEPTED        Solved: 2021-11-23
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1612/submission/136609996
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
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n+1];
    bool vis[n+1]={0};
    vector<int>ans;
    arr[1]=a;
    ans.push_back(a);
    vis[a]=1;
    if(n>2){
        arr[2]=n;
        if(arr[2]==b)--arr[2];
        ans.push_back(arr[2]);
        vis[arr[2]]=1;
    }
    for(int i = 3; i <= n/2; i++){
        arr[i]=arr[i-1]-1;
        if(arr[i]==b)--arr[i];
        if(arr[i]==0)break;
        ans.push_back(arr[i]);
        vis[arr[i]]=1;
    }
    for(int i = 1; i <= n; i++)if(!vis[i]){
        ans.push_back(i);
    }
    if(ans.size()!=n||
    (*min_element(ans.begin(),ans.begin()+n/2))!=a
    ||(*max_element(ans.begin()+n/2,ans.end()))!=b){
        cout<<"-1\n";
        continue;
    }
    for(int i:ans)
        cout<<i<<' ';
    cout<<'\n';
 
}
}
