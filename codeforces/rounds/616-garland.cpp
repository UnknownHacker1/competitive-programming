/*
 * Garland  [1809A]
 * Problem:  https://codeforces.com/problemset/problem/1809/A
 * Verdict:  ACCEPTED        Solved: 2024-03-01
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1809/submission/249210393
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
        int freq[10]{};
        for(int i = 0; i < 4; i++){
            char ch;
            cin>>ch;
            freq[ch-'0']++;
        }
        sort(freq,freq+10,greater<int>());
        if(freq[0]==4){
            cout<<"-1\n";
        }
        else if(freq[0] == 3 && freq[1] == 1){
            cout<<"6\n";
        }
        else cout<<"4\n";
    }
    return 0;
}
