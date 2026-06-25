/*
 * Vasya And Array  [1187C]
 * Problem:  https://codeforces.com/problemset/problem/1187/C
 * Verdict:  ACCEPTED        Solved: 2022-06-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 100 KB
 * Tags:     constructive algorithms, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1187/submission/161246980
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
    int a[n+3]={0};
    for(int i = 1; i <= n; i++){
        a[i]=5e8;
    }
    vector< vector< int > > queries(m,vector<int>(3));
    int pre1[n+3]={0},pre2[n+3]={0};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 3; j++){
            cin>>queries[i][j];
        }
        if(queries[i][0]){
            int l = queries[i][1],r=queries[i][2];
            ++pre1[l+1];
            --pre1[r+1];
            //[l+1,r]
            // pre1 means not allowed to decrease
            ++pre2[l];
            --pre2[r];
            //[l,r-1]
            // pre2 means not allowed to increase
        }
    }
    for(int i = 2; i <= n; i++){
        pre1[i]+=pre1[i-1];
        pre2[i]+=pre2[i-1];
    }
    sort(queries.begin(),queries.end());
    int curplus=1e5,curminus=0;
    for(int j = 0; j < m; j++){
        if(!queries[j][0]){
            if(!is_sorted(a+queries[j][1],a+queries[j][2]+1))
                continue; 
            int l = queries[j][1],r=queries[j][2];
            bool found=0;
            for(int i = l; i < r; i++){
                // to increase
                if(!pre2[i] && a[i] >= 5e8){
                    a[i]+=curplus;
                    --curplus;
                    found=1;
                    break;
                }
            }
            if(!found){
                for(int i = l+1; i <= r; i++){
                    // to decrease
                    if(!pre1[i] && a[i] <= 5e8){
                        a[i]-=curminus;
                        ++curminus;
                        found=1;
                        break;
                    }
                }
            }
        }
    }
    bool ok = 1;
    for(int i = 0; i < m; i++){
        ok&=queries[i][0]==is_sorted(a+queries[i][1],a+queries[i][2]+1);
    }
    cout<<(ok?"YES\n":"NO\n");
    if(ok){
        for(int i = 1; i <= n; i++)
            cout<<a[i]<<' ';
    }
}