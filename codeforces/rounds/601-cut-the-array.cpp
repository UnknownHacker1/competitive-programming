/*
 * Cut the Array  [2144A]
 * Problem:  https://codeforces.com/problemset/problem/2144/A
 * Verdict:  ACCEPTED        Solved: 2025-10-17
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  171 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2144/submission/344104692
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
        int pref[n+1]{};
        for(int i = 1; i <= n; i++)cin>>pref[i],pref[i]+=pref[i-1];
        int al = 0, ar = 0;
        for(int l = 1; l <= n; l++){
            for(int r = l + 1; r < n; r++){
                set<int>st;
                st.insert(pref[l]%3);
                st.insert((pref[r]-pref[l])%3);
                st.insert((pref[n]-pref[r])%3);
                if(st.size()==3||st.size()==1){
                    al=l,ar=r;
                    break;
                }
            }
        }
        cout<<al<<' '<<ar<<'\n';
    }
    return 0;
}