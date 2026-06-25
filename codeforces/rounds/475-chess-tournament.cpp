/*
 * Chess Tournament  [1569B]
 * Problem:  https://codeforces.com/problemset/problem/1569/B
 * Verdict:  ACCEPTED        Solved: 2024-03-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 100 KB
 * Tags:     constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1569/submission/250944167
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
        string s;
        cin>>n>>s;
        char a[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)a[i][j] = 'X';
                else a[i][j] = '=';
            }
        } 
        vector<int>abuse;
        for(int i = 0; i < n; i++){ 
            if(s[i]=='2')abuse.push_back(i);
        }
        for(int i = 0; i < (int)abuse.size(); i++){
            int x = abuse[i], y = abuse[i + 1 < (int)abuse.size() ? i + 1 : 0]; 
            a[x][y] = '+';
            a[y][x] = '-';
            for(int j = 0; j < n; j++) if(j != y && j != x) {
                a[x][j] = '-';
                a[j][x] = '+';
            }
        }
        if((int)abuse.size() < 3 && !abuse.empty()) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout<<a[i][j];
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}