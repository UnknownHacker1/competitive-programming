/*
 * The Number Of Good Substrings  [1217C]
 * Problem:  https://codeforces.com/problemset/problem/1217/C
 * Verdict:  ACCEPTED        Solved: 2022-03-13
 * Language: C++17 (GCC 9-64)
 * Runtime:  46 ms     Memory: 1800 KB
 * Tags:     binary search, bitmasks, brute force
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1217/submission/149549576
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
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
tc{
    string s;
    cin>>s;
    vector<int>ones;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i]=='1')ones.push_back(i);
    }
    ll ans=0;
    for(int i = 0; i < (int)s.size(); i++){
        int idx=i;
        auto it=lower_bound(all(ones),i);
        if(it==ones.end())continue;
        idx=*it;
        for(int j = 1; j <= 18; j++){
            int cur=0;
            if(idx+j-1>=(int)s.size())break;
            int k=idx,curpw;
            for(k = idx,curpw=j-1;k-idx+1<=j;k++,curpw--){
               cur+=(1<<curpw)*(s[k]-'0');
            }
            //cout<<i<<' '<<k-1<<' '<<cur<<'\n';
            if(cur==k-i){ans++;}
        }
    }    
    cout<<ans<<'\n';
}
}