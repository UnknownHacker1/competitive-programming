/*
 * Flint  [102944F]
 * Problem:  Gym/ICPC contest 102944 - problem F
 * Verdict:  ACCEPTED        Solved: 2022-12-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  108 ms     Memory: 12700 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/102944/submission/184505816
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
ll mod = 1e9+7;
int n;
ll a[105];
map<pair<int,int>,ll>mp{};
map<pair<int,int>,ll>vis{}; 
ll rec(int idx, ll g){
    if(idx == n && g == 1)
        return 1;
    if(idx == n)
        return 0;
    auto& v = vis[{idx,g}];
    auto& x = mp[{idx,g}];
    if(v)
        return x;
    v = 1;
    return x = (rec(idx+1,g) + rec(idx+1, __gcd(g,a[idx])))%mod;
}
int main()
{
    ACPLS();   
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<rec(0,0);
}
