/*
 * CCO '08 P5 - Candy  [cco08p5]
 * Problem:  https://dmoj.ca/problem/cco08p5
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-12-23
 * Language: C++20
 * Runtime:  16.694877155 s     Memory: 59576.0 KB
 * Source:   https://dmoj.ca/src/5147082
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
constexpr int MAX = 1e7 / 2 + 2;
int main()
{
    ACPLS();      
    int n;
    cin>>n;
    int k[n+1],c[n+1]; 
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin>>k[i]>>c[i]; 
        sum += k[i] * c[i];
    }
    bitset<MAX>dp{};
    dp[0] = 1;
    vector<int>vis[205];
    vis[0].push_back(0);
    for(int i = 1; i <= n; i++){ 
        vector<int>nvis[205];
        int idx[205]={0};
        int j_mod_ci = 0;
        int j_mod_ci1 = 0;
        for(int j = 0; j <= MAX; j++){
            while(idx[j_mod_ci] + 1 < (int)vis[j_mod_ci].size() && 
                vis[j_mod_ci][idx[j_mod_ci] + 1] <= j){
                ++idx[j_mod_ci];
            }
            if(dp[j] || (vis[j_mod_ci].size() && 0 <= j - vis[j_mod_ci][idx[j_mod_ci]] && j - vis[j_mod_ci][idx[j_mod_ci]] <= k[i] * c[i])){
                dp[j] = 1;
                if(i != n){
                    nvis[j_mod_ci1].push_back(j);
                }
            }
            ++j_mod_ci;
            if(j_mod_ci==c[i])j_mod_ci=0;
            ++j_mod_ci1;
            if(i!=n&&j_mod_ci1==c[i+1])j_mod_ci1=0;
        } 
        for(int i = 0; i < 200; i++)vis[i]=nvis[i];
    }
    for(int i = sum / 2; i >= 0; i--){
        if(dp[i]){
            cout<<sum - 2 * i<<'\n';
            return 0;
        }
    }
}