/*
 * Infinite Prefixes  [1295B]
 * Problem:  https://codeforces.com/problemset/problem/1295/B
 * Verdict:  ACCEPTED        Solved: 2022-05-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 300 KB
 * Tags:     math, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1295/submission/156616831
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
tc{
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    int tot=0;
    for(int i = 0; i < n; i++){
        if(s[i]=='0')tot++;
        else tot--;
    }
    if(tot==0){
        // if theres a prefix = x and tot = 0 answer is infinite
        int cur=0;
        bool inf = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='0')cur++;
            else cur--;
            if(cur==x){
                inf=1;
                break;
            }
        }
        if(inf){
            cout<<"-1\n"; 
        }
        else cout<<"0\n";
        continue;
    }
    // at this point ans is < n 
    int cur=0,ans=0;
    for(int i = 0; i < n; i++){
        if((x-cur)%tot==0&&(x-cur)/tot>=0){
            ans++;
        }
        if(s[i]=='0')cur++;
        else cur--;
    }
    cout<<ans<<'\n';
}
}