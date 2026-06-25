/*
 * NOIP '05 P3: Fire  [noip05p3]
 * Problem:  https://dmoj.ca/problem/noip05p3
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-01-06
 * Language: C++20
 * Runtime:  0.131709255 s     Memory: 4940.0 KB
 * Source:   https://dmoj.ca/src/5190467
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
int f(int n, vector<int>l,vector<int>r){
    vector<int>v;
    v.push_back(0);
    while((int)v.size() != n){
        if(v.size() > 1){
            if(v[v.size() - 2] == r[v.back()]){
                swap(r[v.back()],l[v.back()]);
            }
        }
        v.push_back(r[v.back()]);
    }
    bool ok = 1;
    for(int i = 0; i < n; i++){
        vector<int>mates = {v[(i + n - 1) % n],v[(i + 1) % n]};
        vector<int>wanted = {l[v[i]],r[v[i]]};
        sort(mates.begin(),mates.end());
        sort(wanted.begin(),wanted.end());
        if(mates!=wanted){
            ok = 0;
            break;
        }
    }
    if(!ok){
        return 1e9;
    }
    int freq[n]={0};
    for(int i = 0; i < n; i++){
        freq[(i - v[i] + n) % n]++;
    }
    return n - *max_element(freq,freq+n);
}
int main()
{
    ACPLS("");  
    int n;
    cin>>n; 
    vector<int>l(n),r(n);
    for(int i = 0; i < n; i++){
        cin>>l[i]>>r[i];
        --l[i],--r[i];
    }
    int ans = f(n,l,r);
    swap(l[0],r[0]);
    cout<<(min(ans,f(n,l,r))==1e9?-1:min(ans,f(n,l,r)));
}