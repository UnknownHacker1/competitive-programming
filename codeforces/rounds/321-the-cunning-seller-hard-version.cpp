/*
 * The Cunning Seller (hard version)  [2132C2]
 * Problem:  https://codeforces.com/problemset/problem/2132/C2
 * Verdict:  ACCEPTED        Solved: 2025-09-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     binary search, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2132/submission/337090794
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 3;
#define int long long
int sod(int n){
    int cnt = 0;
    for(int i = 19, x = 1162261467; i >= 0; i--, x /= 3){
        while(n>=x){
            n-=x; 
            ++cnt;
        } 
    }  
    return cnt;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k; 
        if(sod(n) > k){
            cout<<"-1\n";
            continue;
        } 
        k -= sod(n);
        int cnt[20]{}; 
        for(int x = 1162261467, i = 19; i >= 0; i--, x /= 3){
            while(n>=x){
                n-=x;
                cnt[i]++;
            }
            int lim = min(k/2,cnt[i]);
            if(i > 0){
                cnt[i - 1] += 3*lim;
                k -= 2 * lim;
                cnt[i] -= lim;
            }
        }
        ll ans = 0;
        for(int i = 0, x = 1; i < 20; i++, x *= 3){
            ans += cnt[i] * (3*x + i*(x/3));
        }
        cout << ans << '\n';
    }
    return 0;
}