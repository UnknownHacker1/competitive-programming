/*
 * Save the Magazines  [1743C]
 * Problem:  https://codeforces.com/problemset/problem/1743/C
 * Verdict:  ACCEPTED        Solved: 2024-02-27
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 2900 KB
 * Tags:     constructive algorithms, dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1743/submission/248478659
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;  
        char ch;
        vector<pair<int, int>>ranges;
        int lst = -1;
        for(int i = 0; i < n; i++){ 
            cin>>ch;
            if(ch == '0'){
                if(lst + 1 <= i - 1){
                    ranges.push_back({lst + 1, i - 1});
                    //cout<<lst+1<<' '<<i-1<<'\n';
                }
                lst = i;
            }
        }
        if(ch=='1'){
            ranges.push_back({lst + 1, n - 1});
            //cout<<lst+1<<' '<<n-1<<'\n';
        }
        //cout<<'\n';
        int a[n],ans=0;
        for(auto&i:a)cin>>i;
        for(auto [l, r] : ranges){
            int mn = 1e9, sum=0; 
            for(int i = l; i <= r; i++)mn = min(mn, a[i]), sum += a[i];
            if(l > 0) ans += max(sum, sum - mn + a[l - 1]);
            else ans += sum;
        }
        cout<<ans<<'\n';
    }
    return 0;
}