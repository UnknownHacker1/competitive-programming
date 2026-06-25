/*
 * COCI '13 Contest 1 #5 Organizator  [coci13c1p5]
 * Problem:  https://dmoj.ca/problem/coci13c1p5
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-08-30
 * Language: C++20
 * Runtime:  1.267715215 s     Memory: 35528.0 KB
 * Source:   https://dmoj.ca/src/4805931
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
    int tttttt,subtask;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
ll freq[(int)2e6+5],res[(int)2e6+5];
int main()
{
    ACPLS("");  
    int n,x;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>x;
        arr[i]=x;
        freq[x]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 2000000; i++){
        for(int j = i; j <= 2000000; j+=i){
            res[i]+=freq[j];
        }
    }
    for(ll i = 1; i <= 2000000; i++){
        if(res[i]<2)continue;
        ans = max(ans, i * res[i]);
    }
    cout<<ans<<'\n';
}