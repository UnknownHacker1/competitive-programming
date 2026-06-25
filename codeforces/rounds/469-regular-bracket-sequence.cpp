/*
 * Regular Bracket Sequence  [1469A]
 * Problem:  https://codeforces.com/problemset/problem/1469/A
 * Verdict:  ACCEPTED        Solved: 2020-12-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1469/submission/102587047
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
typedef long long ll;
#define f first
#define s second
ll POW(ll expo, ll power) {
    ll res = expo; if (!power) return 1; while (--power) res *= expo; return res;
}
ll sum_range2d(int i, int j, int k, int l, vector<vector<ll>>& s) {
    return s[k][l] - s[k][j - 1] - s[i - 1][l] + s[i - 1][j - 1];
}
ll gcd(ll a, ll b) {
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
bool intersect(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
// End
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        if(s[0]==')' || s[(int)s.size()-1]=='(') {
            cout<<"NO\n";
            continue;
        }
        int cntR=0, cntL=0;
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i]=='(') ++cntR;
            else if(s[i]==')') ++cntL;
        }
        int v = s.size() - (cntR+cntL);
        int x = abs(cntL-cntR);
        if(v>=x) {
            v-=x;
            if(cntL<cntR) cntL+=x;
            else cntR+=x;
        }
        else {cout << "NO\n"; continue;}
        if(v%2==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
