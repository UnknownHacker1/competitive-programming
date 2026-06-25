/*
 * Concatenation of Arrays  [2024C]
 * Problem:  https://codeforces.com/problemset/problem/2024/C
 * Verdict:  ACCEPTED        Solved: 2025-03-05
 * Language: C++17 (GCC 7-32)
 * Runtime:  515 ms     Memory: 10000 KB
 * Tags:     constructive algorithms, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2024/submission/309063839
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
        array<int,2> a[n];
        map<int,int>mp;
        map<int,int>revMp;
        for(int i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1];
            mp[a[i][0]],mp[a[i][1]];
        }
        int idx=0;
        for(auto&it:mp)it.second=idx++;
        for(int i = 0; i < n; i++){
            revMp[mp[a[i][0]]]=a[i][0];
            revMp[mp[a[i][1]]]=a[i][1];
            a[i][0] = mp[a[i][0]];
            a[i][1] = mp[a[i][1]];
        }
        sort(a, a + n, [](array<int,2> first, array<int,2> second){
            /*if(first[0]+first[1]==second[0]+second[1]){
                return first[0]<second[0];
            }*/
            return first[0]+first[1] < second[0]+second[1];
        });
        for(int i = 0; i < n; i++) cout << revMp[a[i][0]] << ' ' << revMp[a[i][1]] << ' ';
        cout<<'\n'; 
    }
	return 0;
}
