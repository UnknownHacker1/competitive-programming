/*
 * Perfecto  [2071B]
 * Problem:  https://codeforces.com/problemset/problem/2071/B
 * Verdict:  ACCEPTED        Solved: 2025-02-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  343 ms     Memory: 12900 KB
 * Tags:     brute force, constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2071/submission/308327564
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;   
bool perfectSquare(ll x){
    ll sq = sqrt(x);
    return sq*sq == x;
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*for(int j = 1; j <= 1000; j++){
        assert(perfectSquare(j*j));
    }*/
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int>st;
        for(int i = 1; i <= n; i++)st.insert(-i);
        vector<int>ans;
        ll cur = 0;
        while((int)ans.size() < n){
            bool found=0;
            for(auto it = st.begin(); it != st.end(); ++it){
                if(!perfectSquare(cur - (*it))){
                    found=1;
                    ans.push_back(-(*it));
                    cur -= (*it);
                    st.erase(it);
                    break;
                }
            }
            if(!found){
                //cout<<"brah\n";
                ans.clear();
                ans.push_back(-1);
                break;
            }
        }
        if(!perfectSquare(cur))for(int i : ans)cout<<i<<' ';
        else cout<<-1;
        cout<<'\n';

    }
	return 0;
}
