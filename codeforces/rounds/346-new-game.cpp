/*
 * New Game  [2025C]
 * Problem:  https://codeforces.com/problemset/problem/2025/C
 * Verdict:  ACCEPTED        Solved: 2025-03-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  312 ms     Memory: 9100 KB
 * Tags:     binary search, brute force, greedy, implementation, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2025/submission/309960264
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;     
ll mxSubarraySum(vector<ll>&a, int k){ 
    int n = (int)a.size();
    deque<ll>dq; 
    ll ans = -1e18,cur=0,mn=1e18; 
    multiset<ll>ms;
    ms.insert(0);
    dq.push_back(0);
    for(int i = 0; i < n; i++){
        cur += a[i];
        if(dq.size() == k){
            ms.erase(ms.find(dq.front()));
            dq.pop_front();
        }
        ans = max(ans, cur - *ms.begin());
        dq.push_back(cur);
        ms.insert(cur);
    }
    return ans;
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        map<int,int>freq{};
        vector<ll>v;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            freq[x]++;
        }
        ll ans = 0;
        v.push_back(freq.begin()->second);
        for(auto it = next(freq.begin()); it != freq.end(); ++it){
            if(prev(it)->first + 1 != it->first){
                ans=max(ans, mxSubarraySum(v, k+1));
                v.clear(); 
            }
            v.push_back(it->second);
        }
        if(v.size())ans=max(ans,mxSubarraySum(v,k+1));
        cout<<ans<<'\n';
    }
    return 0;
}
