/*
 * Hidden Permutations  [1621C]
 * Problem:  https://codeforces.com/problemset/problem/1621/C
 * Verdict:  ACCEPTED        Solved: 2025-03-19
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  249 ms     Memory: 100 KB
 * Tags:     dfs and similar, interactive, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1621/submission/311454617
 */

 
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
void out(vector<int>&v){
    for(int i = 0; i + 1 < (int)v.size(); i++){
        cout<<"1 "<<v[i]+1<<' '<<v.back()+1<<'\n';
    }
}
int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1]{}; 
        bool done=0;
        for(int i = 1; i <= n; i++){
            int cur; 
            cout<<"? "<<i<<endl;
            cin>>cur;
            while(!a[cur]){
                cout<<"? "<<i<<endl;
                int x;
                cin>>x;
                cout<<endl;
                a[cur]=x;
                cur=x;
            }
        }
        cout<<"! ";
        for(int i = 1; i <= n; i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}