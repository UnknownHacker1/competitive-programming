/*
 * Constructive Problem  [1819A]
 * Problem:  https://codeforces.com/problemset/problem/1819/A
 * Verdict:  ACCEPTED        Solved: 2025-03-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  280 ms     Memory: 8600 KB
 * Tags:     brute force, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1819/submission/308640584
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
    int n,mex,mx=0;
    cin>>n;
    mex=n;
    int a[n];
    map<int,vector<int>>occ;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        occ[a[i]].push_back(i);
        mx=max(mx,a[i]);
    }
    for(int i = 0; i < n; i++){
        if(occ[i].empty()){
            mex = i;
            break;
        }
    }
    // scenario 1: mex-1 is max 
    // exist element < mex with freq > 1 ? yes : no 
    if(mx == mex - 1){
        bool ok = 0;
        for(int i = 0; i < mex; i++){
            if(occ[i].size() > 1){
                //cout<<i<<' ';
                ok = 1;
                break;
            }
        }
        cout<<(ok ? "Yes\n": "No\n");
        continue;
    }
    // scenario 2: mex + 1 exists 
    // setting mex to everythign b.w. first and last (mex + 1) will make answer (mex + 1) ? yes : no
    // answer becomes mex + 1 if everything < mex still has non-zero freq
    if(!occ[mex + 1].empty()){
        bool ok = 1;
        int l = occ[mex+1].front(),r=occ[mex+1].back(); 
        for(int i = l; i <= r; i++){
            //cout<<a[i]<<' ';
            occ[a[i]].pop_back();
        }
        //cout<<'\n';
        for(int i = 0; i < mex; i++){ 
            if(occ[i].empty()){
                ok = 0;
                break;
            }
        }
        //cout<<'\n';
        cout<<(ok ? "Yes\n" : "No\n");
        continue;
    }
    // scenario 3: there exists elements greater than mex and mex + 1 doesnt exist, answer is always Yes
    cout<<"Yes\n";
    }
	return 0;
}
