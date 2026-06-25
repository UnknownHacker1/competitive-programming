/*
 * Double Sort  [1681C]
 * Problem:  https://codeforces.com/problemset/problem/1681/C
 * Verdict:  ACCEPTED        Solved: 2025-03-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  124 ms     Memory: 0 KB
 * Tags:     implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1681/submission/311395844
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(auto&i:a)cin>>i;
        for(auto&i:b)cin>>i;
        vector<pair<int,int>>ans;
        for(int j = 0; j < n; j++){
            for(int i = 0; i + 1 < n; i++){
                if(a[i]>a[i+1]||b[i]>b[i+1]){
                    ans.push_back({i,i+1});
                    swap(a[i],a[i+1]);
                    swap(b[i],b[i+1]);
                }
            }
        }
        if(!is_sorted(a,a+n) || !is_sorted(b,b+n)){
            cout<<"-1\n";
        }else{
            cout<<(int)ans.size()<<'\n';
            for(auto&p:ans)cout<<p.first+1<<' '<<p.second+1<<'\n';
        }
    }
    return 0;
}