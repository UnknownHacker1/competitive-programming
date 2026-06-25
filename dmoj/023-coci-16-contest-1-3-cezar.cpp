/*
 * COCI '16 Contest 1 #3 Cezar  [coci16c1p3]
 * Problem:  https://dmoj.ca/problem/coci16c1p3
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-06-18
 * Language: C++20
 * Runtime:  0.067005934 s     Memory: 3500.0 KB
 * Source:   https://dmoj.ca/src/5595583
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
vector<int>adj[270];
map<char,char>mp{};
char cur = 'z';
bool vis[270];
void dfs(char node){
    if(vis[node])
        return;
    vis[node]=1;
    if(cur<'a')return; 
    for(char child : adj[node]){
        dfs(child);
    }
    mp[node]=cur;
    cur--;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int n;
    cin>>n;
    string s[n];
    for(int i = 0; i < n; i++)cin>>s[i];
    int a[n];
    for(int i = 0; i < n; i++)cin>>a[i], --a[i];
    int has[270]={0};
    for(int i = 1; i < n; i++){
        int j;
        int sz = min(s[a[i]].size(), s[a[i - 1]].size());
        for(j = 0; j < sz; j++){
            if(s[a[i]][j] != s[a[i - 1]][j]){
                break;
            }
        }
        if(j != sz){
            adj[s[a[i - 1]][j]].push_back(s[a[i]][j]);
            has[s[a[i]][j]] = 1;
        }
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        if(!has[ch]){
            dfs(ch);
        }
    } 
    string nw[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (int)s[i].size(); j++){
            s[i][j] = mp[s[i][j]]; 
            nw[i].push_back(s[i][j]);
        } 
    }
    sort(nw, nw+n); 
    bool ok = 1;
    for(int i = 0; i < n; i++){ 
        if(find(nw, nw + n, s[a[i]]) - nw != i){
            ok = 0;
            break;
        }
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        if(mp[ch] == 0){
            ok = 0;
            break;
        }
    }
    if(ok){
        cout<<"DA\n";
        for(char ch = 'a'; ch <= 'z'; ch++){
            cout<<mp[ch];
        }
        cout<<'\n';
    }else{
        cout<<"NE\n"; 
    }
    return 0;
}