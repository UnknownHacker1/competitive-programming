/*
 * For Wizards, the Exam Is Easy, but I Couldn't Handle It  [2072D]
 * Problem:  https://codeforces.com/problemset/problem/2072/D
 * Verdict:  ACCEPTED        Solved: 2025-02-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 0 KB
 * Tags:     brute force, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2072/submission/307716187
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
        int n;
        cin>>n;
        int a[n];
        for(auto&i:a)cin>>i;
        int ansl=1,ansr=1,res=0;
        for(int i = 0; i < n; i++){
            int cur=0,mxPref = 0,mxPrefR=i;
            for(int j = i + 1; j < n; j++){
                if(a[i]>a[j])cur++;
                if(a[i] < a[j])cur--;
                if(cur > mxPref){
                    mxPref = cur;
                    mxPrefR = j;
                }
            }
            if(mxPref>res){
                ansl = i+1;
                ansr = mxPrefR + 1;
                res = mxPref;
            }
        }
        cout<<ansl<<' '<<ansr<<'\n';
    }
	return 0;
}
