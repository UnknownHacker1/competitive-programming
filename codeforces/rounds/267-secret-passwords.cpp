/*
 * Secret Passwords  [1263D]
 * Problem:  https://codeforces.com/problemset/problem/1263/D
 * Verdict:  ACCEPTED        Solved: 2021-02-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 15700 KB
 * Tags:     dfs and similar, dsu, graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1263/submission/106468869
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
/// BidoTeima legacy functions
using ll = long long;
unsigned long long POW(unsigned long long a, unsigned long long b) {
    unsigned long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
ll sum_range2d(ll i, ll j, ll k, ll l, vector<vector<ll>>& sum) {
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
ll GCDAC(ll a, ll b) {
    if(b==0)
        return a;
 
    return GCDAC(b, a%b);
}
ll gcd(ll a, ll b) {
    if(a<b)swap(a,b);
    return GCDAC(a, b);
}
ll dist(ll X1, ll Y1, ll X2, ll Y2) {
    return sqrt(POW(X1 - X2, 2) + POW(Y1 - Y2, 2));
}
bool intersect(pair<ll, ll> p1, pair<ll, ll> p2) {
    ll x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
    return (x1 >= y1 && x1 <= y2) ||
        (x2 >= y1 && x2 <= y2) ||
        (y1 >= x1 && y1 <= x2) ||
        (y2 >= x1 && y2 <= x2);
}
bool isPrime(ll n) {
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
/*const ll maxn = 3000;
ll C[maxn + 1][maxn + 1];
void bin_coeff()
{
    C[0][0] = 1;
    for (ll n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (ll k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}*/
/*vector<bool> prime(10000005, true);
void sievePrime(ll n)
{
    prime[1]=false;
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}*/
bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
/// End of BidoTeima legacy functions
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define fr first
#define sc second
#define fast     ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
//End
int MAXN='z'+5;
vector<bool> vis(MAXN,false);
vector<vector<int>> adj(MAXN);
void dfs(int u) {
    if(vis[u]) return;
    vis[u]=true;
    for(auto v : adj[u])
        dfs(v);
}
int main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ///bin_coeff();
    fast
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int i = 1; i < (int)s.length(); i++) {
            adj[s[i]].push_back(s[i-1]);
            adj[s[i-1]].push_back(s[i]);
        }
        adj[s[0]].push_back(s[0]);
    }
    int ans = 0;
    for(int i = 'a'; i <= 'z'; i++) {
        if(vis[i]==false&&adj[i].size()) {
            ++ans;
            dfs(i);
        }
    }
    cout<<ans;
}