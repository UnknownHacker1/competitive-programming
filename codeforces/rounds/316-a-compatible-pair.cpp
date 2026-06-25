/*
 * A Compatible Pair  [934A]
 * Problem:  https://codeforces.com/problemset/problem/934/A
 * Verdict:  ACCEPTED        Solved: 2022-11-04
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, games
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/934/submission/179303994
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
    ACPLS("");  
    int n,m;
    cin>>n>>m;
    ll a[n],b[m];
    for(auto&i:a)cin>>i;
    for(auto&i:b)cin>>i;
    ll mx = -1e18;
    int mxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i]*b[j] > mx){
                mx=a[i]*b[j];
                mxi=i;
            }
        }
    }
    ll ans = -1e18;
    for(int i = 0; i < n; i++){
        if(i == mxi)continue;
        for(int j = 0; j < m; j++){
            ans=max(ans,a[i]*b[j]);
        }
    }
    cout<<ans<<'\n';
}