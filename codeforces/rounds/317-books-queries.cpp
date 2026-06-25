/*
 * Books Queries  [1066C]
 * Problem:  https://codeforces.com/problemset/problem/1066/C
 * Verdict:  ACCEPTED        Solved: 2022-06-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 2600 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1066/submission/160988384
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
// BOOKS QUERIES
int main()
{
    ACPLS();  
    int q;
    cin>>q; 
    bool isL[(int)2e5+3]={0};
    int aL[(int)2e5+3],aR[(int)2e5+3],a[(int)2e5+3];
    int counterL=0,counterR=0,counter=0;
    for(int i = 0; i < q; i++){
        char type;
        cin>>type; 
        int id;
        cin>>id;
        counterL+=(type=='L');
        counterR+=(type=='R');
        if(type!='?'){
            a[id]=counter;
            aL[id]=counterL;
            aR[id]=counterR;
            ++counter;
        }
        if(type=='L'){
            isL[id]=1;
        }
        else if(type=='?'){
            int dist_left,dist_right;
            if(isL[id]){
                 dist_left = counterL-aL[id];
                dist_right = a[id] + counterR - aR[id];
            }
            else{
                 dist_right = counterR - aR[id];
                 dist_left = a[id] + counterL - aL[id];
            } 
            cout<<min(dist_left,dist_right)<<'\n';
        }
    }
}
// keep track of the rights and lefts added
// before and after a num was added