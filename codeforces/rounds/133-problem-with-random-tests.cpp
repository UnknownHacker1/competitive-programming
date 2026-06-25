/*
 * Problem with Random Tests  [1743D]
 * Problem:  https://codeforces.com/problemset/problem/1743/D
 * Verdict:  ACCEPTED        Solved: 2024-02-27
 * Language: C++20 (GCC 11-64)
 * Runtime:  155 ms     Memory: 20000 KB
 * Tags:     brute force, dp, greedy, probabilities
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1743/submission/248607539
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 3;
const ll mod = 1e18 + 3;
ll pw2[N], pw2inv[N];
ll mul(ll a, ll b){
    return (__int128(a) * b) % mod;
}

int main(){
    int n; cin >> n;
    string s = ""; cin >> s;
    string ans = s;
    for(int i=0; i<min(n, 30); i++) {
        string t = s;
        for(int j=0; j<n-i; j++) {
            t[i + j] = max(s[j], s[i + j]);
        }
        ans = max(ans, t);
    }
    int i = 0;
    while(i < n-1 && ans[i] == '0') i += 1;
    cout << ans.substr(i) << "\n";
    return 0;
}