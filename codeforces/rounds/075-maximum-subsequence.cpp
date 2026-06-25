/*
 * Maximum Subsequence  [888E]
 * Problem:  https://codeforces.com/problemset/problem/888/E
 * Verdict:  ACCEPTED        Solved: 2022-06-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 2600 KB
 * Tags:     bitmasks, divide and conquer, meet-in-the-middle
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/888/submission/160461751
 */

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
#define tc int tttt;cin>>tttt;while(tttt--)
int main()
{
    ACPLS(); 
    int n,m;
    cin>>n>>m;
    int a[n];
    for(auto&i:a)cin>>i,i%=m;
    vector<int>l1,l2;
    l1.push_back(0);
    l2.push_back(0);
    for(int i = 0; i < n/2; i++){
        int k=(int)l1.size();
        for(int j = 0; j < k; j++){
            l1.push_back((a[i]+l1[j])%m);
        }
    }
    for(int i = n/2; i < n; i++){
        int k=(int)l2.size();
        for(int j = 0; j < k; j++){
            l2.push_back((a[i]+l2[j])%m);
        }
    }
    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());
    int ans=max(l1.back(),l2.back());
    for(int i = 0; i < (int)l1.size(); i++){
        int idx = upper_bound(l2.begin(),l2.end(),m-1-l1[i])-l2.begin()-1;
        if(idx==-1)continue;
        ans=max(ans,l1[i]+l2[idx]);
    }
    cout<<ans;
}