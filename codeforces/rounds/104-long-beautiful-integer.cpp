/*
 * Long Beautiful Integer  [1268A]
 * Problem:  https://codeforces.com/problemset/problem/1268/A
 * Verdict:  ACCEPTED        Solved: 2022-01-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 1900 KB
 * Tags:     constructive algorithms, greedy, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1268/submission/142166026
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string pref;
    for(int i = 0; i < k; i++){
        pref+=s[i];
    } 
    string pref1=pref;
    bool carry=1;
    for(int i = k-1; i >= 0; i--){
        int x = pref1[i]-'0'+carry;
        if(x<10){
            carry=0;
            pref1[i]=x+'0';
        }
        else{
            pref1[i]='0';
        }
    }
    string res1=pref,res2=pref1;
    while(res1.size()+pref.size()<=s.size()){
        res1+=pref;
        res2+=pref1;
    }
    for(int i = 0; i < k; i++){
        if(res1.size()<s.size()){
            res1.push_back(pref[i]);
            res2.push_back(pref1[i]);
        }else break;
    }
    cout<<n<<'\n';
    if(res1>=s)
        cout<<res1;
    else cout<<res2;
}
 
