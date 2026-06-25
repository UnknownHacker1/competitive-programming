/*
 * Tandem Repeats?  [1948D]
 * Problem:  https://codeforces.com/problemset/problem/1948/D
 * Verdict:  ACCEPTED        Solved: 2025-03-23
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 100 KB
 * Tags:     brute force, strings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1948/submission/312067461
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N = 5005;
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){  
        string s;
        cin>>s;
        int n = (int)s.size();
        int ans=0;
        for(int k = n/2; k >= 1; k--){
            int cnt=0;
            for(int i = 0; i + 1 < k; i++){
                cnt+=(s[i]!=s[i+k]&&s[i]!='?'&&s[i+k]!='?');
            }
            for(int i = k - 1; i + k < n; i++){
                cnt+=(s[i]!=s[i+k]&&s[i]!='?'&&s[i+k]!='?');
                if(i >= k){
                    cnt -= (s[i - k] != s[i] && s[i - k] != '?' && s[i] != '?');
                }
                if(cnt == 0){
                    ans=k;
                    break;
                }
            }
            if(ans)break;
        } 
        cout<<2*ans<<'\n';
    }
    return 0;
}