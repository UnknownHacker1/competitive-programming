/*
 * BA-String  [1620C]
 * Problem:  https://codeforces.com/problemset/problem/1620/C
 * Verdict:  ACCEPTED        Solved: 2022-09-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  78 ms     Memory: 0 KB
 * Tags:     brute force, dp, greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1620/submission/170950990
 */

/// isA AC
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
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
int main()
{
    ACPLS("");  
tc{
    ll n,k; 
    ll x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    if(!k){
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i]!='*')cout<<s[i];
        }
        cout<<'\n';
        continue;
    }
    vector<ll>lim;
    ll cur = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '*'){
            cur += k;
        }
        else if(cur != 0){
            lim.push_back(cur);
            cur = 0;
        }
    }
    if(cur != 0){
        lim.push_back(cur);
    }
    --x;
    vector<ll>coefficients(lim.size());
    for(int i = (int)lim.size() - 1; i >= 0; i--){
        coefficients[i] = x % (lim[i]+1);
        x /= (lim[i]+1);
    }
    int idx = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '*' && (i+1 == (int)s.size() || s[i + 1] == 'a')){
            for(int j = 0; j < coefficients[idx]; j++){
                cout<<'b';
            }
            idx++;
        }
        else if(s[i] == 'a'){
            cout<<s[i];
        }
    }
    cout<<'\n';
}
}   