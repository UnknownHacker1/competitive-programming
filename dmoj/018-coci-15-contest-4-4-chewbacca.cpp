/*
 * COCI '15 Contest 4 #4 Chewbacca  [coci15c4p4]
 * Problem:  https://dmoj.ca/problem/coci15c4p4
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2022-12-04
 * Language: C++20
 * Runtime:  0.417886388 s     Memory: 3404.0 KB
 * Source:   https://dmoj.ca/src/5089845
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
ll k;
ll n;
vector<ll> f(ll x){
    ll a = 0, s = 1, p = 1;
    while(s + (p * k) < x){
        p *= k;
        s += p;
        a++; 
    }
    vector<ll>ret; 
    ret.push_back(x);
    while(x > 1){
        ll i = (x - s - 1) / k;
        ll bef = s - p;
        x = i + bef + 1;
        ret.push_back(x);
        s -= p;
        p /= k;
    }
    return ret;
}
int main()
{
    ACPLS();  
    cin>>n>>k;
    int q;
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y; 
        if(k == 1){
            cout<<abs(x - y)<<'\n';
            continue;
        }
        vector<ll>v1 = f(x), v2 = f(y);
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        /*for(ll i : v1)cout<<i<<' ';
        cout<<'\n';
        for(ll i : v2)cout<<i<<' ';
        cout<<'\n';*/
        int i = 0;
        for(; i < (int)min(v1.size(),v2.size()) && v1[i] == v2[i]; i++);
        //cout<<i<<'\n';
        cout<<(int)v1.size() + (int)v2.size() - 2 * (i);
        cout<<'\n';
    }
}