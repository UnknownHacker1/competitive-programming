/*
 * You Soared Afar With Grace  [2084C]
 * Problem:  https://codeforces.com/problemset/problem/2084/C
 * Verdict:  ACCEPTED        Solved: 2025-04-05
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  452 ms     Memory: 14000 KB
 * Tags:     constructive algorithms, data structures, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2084/submission/314110643
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
        map<int,int>mp;
        for(int i = 0; i < n; i++){
            cin>>b[i];
            mp[a[i]]=b[i];
        }
        bool ok = 1;
        int cnteq=0;
        for(auto&it:mp){
            if(mp[it.second]!=it.first)ok=0;
            if(it.first==it.second)cnteq++;
        }
        if(cnteq>(n&1) || !ok){
            cout<<"-1\n";
            continue;
        }
        vector<int>l;
        vector<int>r;
        int mid=-1;
        bool marked[n+1]{};
        for(int i = 1; i <= n; i++){
            if(marked[i])continue;
            if(mp[i]==i){
                mid=i;
                continue;
            }
            marked[mp[i]]=1;
            l.push_back(i);
            r.push_back(mp[i]);
        }
        reverse(r.begin(),r.end());
        vector<int>target;
        for(auto&i:l)target.push_back(i);
        if(n&1)target.push_back(mid);
        for(auto&i:r)target.push_back(i);
        int location[n+1];
        for(int i = 0; i < n; i++)location[a[i]]=i;
        vector<pair<int,int>>ans;
        for(int i = 0; i < n; i++){
            if(a[i] != target[i]){
                ans.push_back({i+1,location[target[i]]+1}); 
                a[location[target[i]]]=a[i];
                location[a[i]]=location[target[i]];
                location[target[i]]=i;
                a[i]=target[i]; 
            }
        }
        cout<<(int)ans.size()<<'\n';
        for(auto&p:ans)cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}