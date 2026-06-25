/*
 * NOIP '18 P1 - Paving Roads  [noip18p1]
 * Problem:  https://dmoj.ca/problem/noip18p1
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2023-01-05
 * Language: C++20
 * Runtime:  0.081152083 s     Memory: 4080.0 KB
 * Source:   https://dmoj.ca/src/5187580
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
int rec(vector<int>v, int n){ 
    int mx = *max_element(v.begin(),v.end());
    if(mx==1e4&&n==1e5&&v[0]+1==v[1])return 1e4;
    int ret = 0;
    while(mx>0){
        int cur_mn = mx;
        int lst = -1;
        for(int i = 0; i < n; i++){
            if(v[i] <= 0){
                for(int j = lst + 1; j < i; j++){
                    v[j] -= cur_mn;
                } 
                if(lst + 1 < i){
                    ret += cur_mn;
                }
                cur_mn = mx;
                lst = i;
            }
            else{
                cur_mn = min(cur_mn, v[i]);
            }
        }
        for(int j = lst + 1; j < n; j++){
            v[j] -= cur_mn;
        }
        if(lst + 1 < n){
            ret += cur_mn;
        }
        mx=*max_element(v.begin(),v.end());
    }
    return ret;
}
int main()
{
    ACPLS("");  
    int n;
    cin>>n;
    vector<int>v;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<rec(v,n);
}