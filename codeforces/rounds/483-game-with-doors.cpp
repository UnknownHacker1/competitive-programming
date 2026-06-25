/*
 * Game with Doors  [2004B]
 * Problem:  https://codeforces.com/problemset/problem/2004/B
 * Verdict:  ACCEPTED        Solved: 2025-03-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  61 ms     Memory: 100 KB
 * Tags:     brute force, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2004/submission/308927224
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;   
bool inside(int i, int l, int r){
    return i >= l && i <= r;
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){ 
        int l,r,L,R;
        cin>>l>>r>>L>>R;
        int ans = 0;
        for(int d = 1; d <= 99; d++){
            int room1=d,room2=d+1;
            if((inside(room1, l, r) && inside(room2, L, R)) || 
                (inside(room2, l, r) && inside(room1, L, R))) ans++;
            // room 1 is in [l,r] and room2 is in [L, R] 
            //or
            // room 2 is in [l,r] and room1 is in [L, R]  
        } 
        if(min(r,R)+1<max(l,L)) ans = 1;
        cout<<ans<<'\n';
    }
	return 0;
}
