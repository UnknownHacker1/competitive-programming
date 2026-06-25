/*
 * Mukhammadali and the Smooth Array  [2167G]
 * Problem:  https://codeforces.com/problemset/problem/2167/G
 * Verdict:  ACCEPTED        Solved: 2025-10-28
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  218 ms     Memory: 100 KB
 * Tags:     data structures, dp
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2167/submission/346381698
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;     

const int N = 8001;


int a[N],c[N],n;

/*
ll dp[N][N];
ll rec(int idx, int prv){
    if(idx == n) return 0;

    if(dp[idx][prv] != -1) return dp[idx][prv];

    ll ret = 1e18;

    if(a[idx] < prv){
        ret = rec(idx + 1, prv) + c[idx];
    }else{
        ret = min(rec(idx + 1, prv) + c[idx], rec(idx + 1, a[idx]));
    }
    return dp[idx][prv] = ret;
}*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    int t;
    cin>>t;
    while(t--){ 
        cin >> n;
        map<int,int>mp{}; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]];
        }
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        int idx=0;
        for(auto&it:mp){
            it.second=idx++;
        }
        for(int i = 0; i < n; i++) a[i] = mp[a[i]];

        ll dp[(int)mp.size()]; 
        for(int j = 0; j < (int)mp.size(); j++)dp[j]=1e18;
        for(int i = 0; i < a[0]; i++){ 
            dp[i] = c[0];
        }
        dp[a[0]] = 0;
        for(int i = 1; i < n; i++){ 
            ll new_dp[(int)mp.size()];
            for(int j = 0; j < (int)mp.size(); j++)new_dp[j]=1e18;
            for(int j = 0; j < (int)mp.size(); j++){
                new_dp[j] = min(new_dp[j], dp[j] + c[i]);
                if(a[i]>=j){ 
                    new_dp[a[i]] = min(new_dp[a[i]], dp[j]);
                }
            }
            for(int j = 0; j < (int)mp.size(); j++)dp[j]=new_dp[j];
        }
        ll mn = 1e18;
        for(int j = 0; j < (int)mp.size(); j++)mn=min(mn,dp[j]);
        cout << mn << '\n';

    }
    return 0;
}
