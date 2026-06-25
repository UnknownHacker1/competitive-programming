/*
 * Destroy it!  [1176F]
 * Problem:  https://codeforces.com/problemset/problem/1176/F
 * Verdict:  ACCEPTED        Solved: 2025-02-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  374 ms     Memory: 1200 KB
 * Tags:     dp, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1176/submission/307470398
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
int32_t main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    int n;
    cin>>n;
    ll dp[10];
    for(int i = 0; i < 10; i++){
        dp[i]=-1e18;
    }
    ll ans = 0;
    dp[0] = 0;
    while(n--){
        ll new_dp[10]; 
        for(int i = 0; i < 10; i++) new_dp[i]=dp[i];
        int k;
        cin>>k;
        vector<int>mxx[4];
        while(k--){ 
            int c,d;
            cin>>c>>d;
            mxx[c].push_back(d);
        }
        for(int i = 1; i <= 3; i++){
            sort(mxx[i].begin(),mxx[i].end());
            reverse(mxx[i].begin(),mxx[i].end());
        }
        while(mxx[1].size()>3)mxx[1].pop_back(); 
        // options: all 3 (1), best (1) and (2), best 3  
        for(int i = 0; i < 10; i++){ 
            vector<int>mx[4];
            for(int j = 0; j < 4; j++)mx[j]=mxx[j];
            // all 3 (1) 
            ll sm = accumulate(mx[1].begin(),mx[1].end(),0ll);
            int nxt = (i + mx[1].size()) % 10;
            if(!mx[1].empty()){
                new_dp[nxt] = max(new_dp[nxt], dp[i] + sm + (nxt < i ? mx[1][0] : 0));
                // best (1) and (2)
                if(!mx[2].empty()){
                    new_dp[(i + 2) % 10] = max(new_dp[(i + 2) % 10], 
                    dp[i] + mx[1][0] + mx[2][0] + (i >= 8 ? max(mx[1][0], mx[2][0]) : 0));
                }
                // we can try using less (1)s too 
                if(mx[1].size()>1){
                    mx[1].pop_back();
                    nxt = (i + mx[1].size()) % 10;
                    sm = accumulate(mx[1].begin(),mx[1].end(),0ll);
                    new_dp[nxt] = max(new_dp[nxt], dp[i] + sm + (nxt < i ? mx[1][0] : 0));
                }
                if(mx[1].size()>1){
                    mx[1].pop_back();
                    nxt = (i + mx[1].size()) % 10;
                    sm = accumulate(mx[1].begin(),mx[1].end(),0ll);
                    new_dp[nxt] = max(new_dp[nxt], dp[i] + sm + (nxt < i ? mx[1][0] : 0));
                }
            }
            if(!mx[2].empty()){
                nxt = i == 9 ? 0 : i + 1;
                new_dp[nxt]=max(new_dp[nxt], dp[i] + (nxt ? mx[2][0] : 2*mx[2][0]));
            }   
            if(!mx[3].empty()){
                nxt = i == 9? 0 : i + 1;
                new_dp[nxt] = max(new_dp[nxt], dp[i] + (nxt ? mx[3][0] : 2*mx[3][0]));
            }
        }
        for(int i = 0; i < 10; i++){
            dp[i]=new_dp[i];
            ans=max(ans,dp[i]);
        } 
        //cout<<ans<<'\n';
    }
    cout << ans;
	return 0;
}
