/*
 * COCI '15 Contest 2 #2 Geppetto  [coci15c2p2]
 * Problem:  https://dmoj.ca/problem/coci15c2p2
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2024-07-10
 * Language: C++20
 * Runtime:  0.261861395 s     Memory: 3676.0 KB
 * Source:   https://dmoj.ca/src/6484290
 */

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;   

int main()
{  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);     
    int n,m;
    cin>>n>>m;
    vector<int>badFor[n];
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        --a, --b;
        badFor[a].push_back(b);
        badFor[b].push_back(a);
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        bool bad[n]{};
        bool good = 1;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                if(bad[j]){
                    good = 0;
                    break;
                }
                for(int k : badFor[j]){
                    bad[k] = 1;
                }
            }
        }
        if(good) ans++;
    }
    cout<<ans;
    return 0;  
}