/*
 * GCD of an Array  [1493D]
 * Problem:  https://codeforces.com/problemset/problem/1493/D
 * Verdict:  ACCEPTED        Solved: 2022-01-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  1356 ms     Memory: 113800 KB
 * Tags:     brute force, data structures, hashing, implementation, math, number theory, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1493/submission/143136562
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
ll mod = 1e9 + 7;
ll POW(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1)ans = (ans % mod * a % mod) % mod;
        ans = (a % mod * a % mod) % mod;
        b /= 2;
    }
    return ans;
}
int main()
{
    ACPLS();
    vector<int>lp((int)2e5 + 5,0);
    for (ll i = 2; i <= 2e5 + 1; i++) {
        for (ll j = i * i; j <= 2e5 + 1; j += i) {
            if (!lp[j])
                lp[j] = i;
            else lp[j] = min((ll)lp[j], i);
        }
        if (!lp[i])lp[i] = i;
    }
    int n, q;
    cin >> n >> q;
    vector<multiset<int>>st((int)2e5 + 5);
    vector<map<int,int>>freq((int)2e5+5);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (lp[x]) {
            auto& f = freq[i][lp[x]];
            auto& s = st[lp[x]];
            int mn = (s.size() != n ? 0 : *s.begin());
            if (f != 0) {
                assert(s.size() > 0);
                s.erase(s.find(f));
            }
            ++f;
            s.insert(f);
            int newmn = (s.size() != n ? 0 : *s.begin());
            //cout<<mn<<' '<<newmn<<'\n';
            if (newmn > mn) {
                ans = (ans % mod * lp[x] % mod) % mod;
            }
            x /= lp[x];
            assert(s.size() <= n);
        }
        //cout<<'\n';
    }
    //cout<<ans<<'\n';
    while (q--) {
        int i, x;
        cin >> i >> x;
        --i;
        while (lp[x]) {
            auto& f = freq[i][lp[x]];
            auto& s = st[lp[x]];
            int mn = (s.size() != n ? 0 : *s.begin());
            if (f != 0) {
                assert(s.size() > 0);
                s.erase(s.find(f));
            }
            ++f;
            s.insert(f);
            int newmn = (s.size() != n ? 0 : *s.begin());
            //cout<<mn<<' '<<newmn<<'\n';
            if (newmn > mn) {
                ans = (ans % mod * lp[x] % mod) % mod;
            }
            x /= lp[x];
            assert(s.size() <= n);
        }
        cout << ans << '\n';
    }
}

