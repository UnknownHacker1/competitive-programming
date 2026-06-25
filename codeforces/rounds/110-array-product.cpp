/*
 * Array Product  [1042C]
 * Problem:  https://codeforces.com/problemset/problem/1042/C
 * Verdict:  ACCEPTED        Solved: 2025-03-19
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  155 ms     Memory: 1100 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1042/submission/311428599
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    vector<int>v[3];//0->0,1->neg,2->pos
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i]==0)v[0].push_back(i);
        if(a[i]<0)v[1].push_back(i);
        if(a[i]>0)v[2].push_back(i);
    } 
    for(int i = 1; i <= 2; i++) sort(v[i].begin(),v[i].end(),[&](int pos1, int pos2){
        return abs(a[pos1])<abs(a[pos2]);
    });
    if(v[0].empty()){
        // negatives r odd ? remove one negative ! 
        // negatives r even ? do nothing! 
        if(v[1].size()&1){
            cout<<"2 "<<v[1][0]+1<<'\n';
            vector<int>idx;
            for(int i = 1; i < (int)v[1].size(); i++)idx.push_back(v[1][i]);
            for(auto&i:v[2])idx.push_back(i);
            out(idx);
        }else{
            vector<int>idx;
            for(int i = 0; i < n; i++)idx.push_back(i);
            out(idx);
        }
    }else{ 
        // remove all the zeroes and a negative w/ them if the negative count is odd
        if(v[0].size()==n)cout<<"2 "<<v[0][0]+1<<'\n';
        for(int i = (v[0].size()==n); i + 1 < (int)v[0].size(); i++){
            cout<<"1 "<<v[0][i]+1<<' '<<v[0].back()+1<<'\n';
        }
        if(v[1].size()&1)cout<<"1 "<<v[1][0]+1<<' '<<v[0].back()+1<<'\n';
        if(v[0].size()==n||(v[1].size()==1&&v[2].empty()))return 0;
        cout<<"2 "<<v[0].back()+1<<'\n';
        vector<int>idx;
        for(int i = v[1].size()&1; i < (int)v[1].size(); i++)idx.push_back(v[1][i]);
        for(auto&i:v[2])idx.push_back(i);
        out(idx);
    }
    return 0;
}