/*
 * COCI '07 Regional #4 Jednakost  [crci07p4]
 * Problem:  https://dmoj.ca/problem/crci07p4
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2023-02-14
 * Language: C++20
 * Runtime:  0.175795289 s     Memory: 50516.0 KB
 * Source:   https://dmoj.ca/src/5333473
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size() && str != "IIOT")
        moo(str);
    else if(str != "IIOT"){
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
ll val[1005][1005]; 
ll first[1005];
// a[k] * 10^k for each k from i to j
int n;
string s;
ll dp[1001][5005];
ll rec(int i, int curSum){
    if(curSum < 0)
        return 1e9; 
    // try ending here
    if(val[i][n - 1] == curSum){
        //cout<<"OMG";
        return 0;
    }
    // sum(i - distPrev + 1, i)
    if(i==n-1)
        return 1e9;
    if(dp[i][curSum]!=-1)
        return dp[i][curSum];
    ll ret = 1e9; 
    for(int j = first[i] + 1; j < n && val[i][j - 1] != -1; j++){
        ret=min(ret, rec(j, curSum - val[i][j - 1]) + 1);
    }
    return dp[i][curSum]=ret;
}
void build(int i, ll curSum){
    if(val[i][n - 1] == curSum){
        for(int j = i; j < n; j++)
            cout<<s[j];
        return;
    }
    //assert(i<n-1);
    pair<ll,ll>state;
    ll value = 1e9;
    for(ll j = first[i] + 1; j < n && val[i][j - 1] != -1; j++){
        ll x = rec(j, curSum - val[i][j - 1]) + 1;
        if(x < value){
            value = x;
            state={j, curSum - val[i][j - 1]};
        } 
    }
    assert(value<1000);
    for(int j = i; j < state.first; j++){
        cout<<s[j]; 
    }
    cout<<'+';
    build(state.first, state.second);
}
int main()
{ 
    ACPLS("");
    memset(dp,-1,sizeof(dp));
    memset(val,-1,sizeof(val));
    memset(first,-1,sizeof(first));
    string equation;
    cin>>equation;
    ll r=0;
    int i = 0;
    for(; i < (int)equation.size() && equation[i] != '='; i++){
        s+=equation[i];
    }
    n=(int)s.size();
    if(equation[i]=='=')i++;
    for(; i < (int)equation.size(); i++){
        r*=10;
        r+=equation[i]-'0';
    } 
    for(i = 0; i < (int)s.size(); i++){
        ll x = 0;
        for(int j = i; j < (int)s.size() && x < 1e4; j++){
            x*=10;
            x+=s[j]-'0';
            val[i][j]=x; 
            if(x>0&&first[i]==-1)first[i]=j;
        }
    }
    build(0, r);
    cout<<'='<<r<<'\n';
}