/*
 * COCI '09 Contest 3 #5 Patuljci  [coci09c3p5]
 * Problem:  https://dmoj.ca/problem/coci09c3p5
 * Verdict:  ACCEPTED (17.0 pts)   Solved: 2023-08-15
 * Language: C++20
 * Runtime:  0.238060847 s     Memory: 6452.0 KB
 * Source:   https://dmoj.ca/src/5710898
 */

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 5e5 + 3;
vector<int>occ[N];
int f(int x, int l, int r){
    return upper_bound(occ[x].begin(),occ[x].end(),r)-lower_bound(occ[x].begin(),occ[x].end(),l);
}
int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n,c;
    cin>>n>>c;
    int p[n];
    for(int i = 0; i < n; i++){
        cin>>p[i];
        occ[p[i]].push_back(i);
    }
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        --a,--b;
        int it=25;
        int ans=0;
        while(it--){
            int id = (rand()%(b-a+1)) + a;
            int val=p[id];   
            if(f(val,a,b)>((b-a+1)>>1)){
                ans=val;
                break;
            }
        }
        if(!ans){
            cout<<"no\n";
        }else cout<<"yes "<<ans<<'\n';
    }
    return 0;
}