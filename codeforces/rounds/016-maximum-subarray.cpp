/*
 * Maximum Subarray  [1796D]
 * Problem:  https://codeforces.com/problemset/problem/1796/D
 * Verdict:  ACCEPTED        Solved: 2025-02-16
 * Language: C++20 (GCC 13-64)
 * Runtime:  108 ms     Memory: 9700 KB
 * Tags:     data structures, dp, greedy, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1796/submission/306439302
 */

#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
#define int long long
int32_t main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
        int n, k, x;
        cin >> n >> k >> x;
        if(x < 0){
            x *= -1;
            k = n - k;
        }
        int a[n];
        for(int&i:a)cin>>i,i-=x;
        deque<ll>dq; 
        ll ans = -1e18,cur=0,mn=1e18; 
        for(int i = 0; i < n; i++){
            cur += a[i];
            if(i >= k - 1) mn = min(mn, 0ll);
            if(k != 0 && dq.size() == k) { 
                mn=min(mn,dq.front()); 
                dq.pop_front();
            }
            dq.push_back(cur); 
            //cout<<"at "<<i<<" mn is "<<mn<<'\n';
            ans = max(ans, cur - mn);
            if(k == 0) mn = min(mn, cur);
        }  
        //cout<<'\n';
        
        ans += 2 * k * x;
        ans=max(ans,0ll);
        //cout<<ans<<'\n';
        // now let's handle the case where subarray size < k 
        if(k > 1){
            dq.clear();
            for(int&i:a)i += 2*x;
            cur = 0;
            multiset<ll>ms;
            ms.insert(0);
            dq.push_back(0);
            for(int i = 0; i < n; i++){
                cur += a[i];
                if(dq.size() == k){
                    ms.erase(ms.find(dq.front()));
                    dq.pop_front();
                }
                //cout<<"at "<<i<<" mn is "<<*ms.begin()<<'\n';
                ans = max(ans, cur - *ms.begin());
                dq.push_back(cur);
                ms.insert(cur);
            }
        }
        //cout<<'\n';
        cout << ans << '\n';
    }
	return 0;
}
