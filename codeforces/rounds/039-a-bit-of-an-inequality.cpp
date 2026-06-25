/*
 * A BIT of an Inequality  [1957D]
 * Problem:  https://codeforces.com/problemset/problem/1957/D
 * Verdict:  ACCEPTED        Solved: 2025-03-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 100 KB
 * Tags:     bitmasks, brute force, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1957/submission/308916220
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;   
int msb(int x){
    for(int i = 29; i >= 0; i--){
        if(x&(1<<i)) return i;
    }
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t; 
    while(t--){
        int n,x,cnt[30][2]{},cur=0;
        cin>>n;  
        ll sum[30][2]{},ans=0;
        for(int i = 0; i < 30; i++) cnt[i][0] = 1;
        for(int i = 0; i < n; i++){
            cin>>x;
            cur ^= x;
            int b = msb(x); 
            sum[b][0] += cnt[b][0], sum[b][1] += cnt[b][1];
            for(int j = 0; j < 30; j++){
                int s = !!(cur&(1<<j));
                ans += sum[j][s];
                cnt[j][s]++;
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}
