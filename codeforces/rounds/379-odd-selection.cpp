/*
 * Odd Selection  [1363A]
 * Problem:  https://codeforces.com/problemset/problem/1363/A
 * Verdict:  ACCEPTED        Solved: 2021-04-30
 * Language: C++17 (GCC 7-32)
 * Runtime:  951 ms     Memory: 15900 KB
 * Tags:     brute force, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1363/submission/114685954
 */

#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
using namespace std;
// Important functions and defines
/// BidoTeima legacy functions
using ll = long long;
ll mod = (ll)1e9+7;
ll MOD = mod;
int64_t POW(int64_t a, int64_t b)
{
    int64_t res = 1;
    while (b > 0)
    {
        if (b % 2 == 1) res = (res*a);
        a = (a*a);
        b /= 2;
    }
    return res;
}
ll sum_range2d(ll i, ll j, ll k, ll l, vector<vector<ll>>& sum)
{
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
ll GCDAC(ll a, ll b)
{
    if(b==0)
        return a;

    return GCDAC(b, a%b);
}
ll gcd(ll a, ll b)
{
    if(a<b)swap(a,b);
    return GCDAC(a, b);
}
ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
ll dist(ll X1, ll Y1, ll X2, ll Y2)
{
    return sqrt(POW(X1 - X2, 2) + POW(Y1 - Y2, 2));
}
bool intersect(pair<ll, ll> p1, pair<ll, ll> p2)
{
    ll x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
    return (x1 >= y1 && x1 <= y2) ||
           (x2 >= y1 && x2 <= y2) ||
           (y1 >= x1 && y1 <= x2) ||
           (y2 >= x1 && y2 <= x2);
}
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
ll inverse(ll n)
{
    return POW(n%mod,mod-2);
}
bool mul_overflow(ll x, ll y) {
    return (log2(x)+log2(y)) >= 64.0;
}
ll ceili(ll x,ll y){
    return (x + y - 1) / y;
}
/*const ll maxn = 30;
ll C[maxn + 1][maxn + 1];
void bin_coeff()
{
    C[0][0] = 1;
    for (ll n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (ll k = 1; k < n; ++k)
            C[n][k] = ((C[n - 1][k - 1]) + (C[n - 1][k]));
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
/// End of BidoTeima legacy functions
#define ALL(x) (x).begin(),(x).end()
#define all(cont) (cont).begin(), (cont).end()
#define rall(cont) (cont).rbegin(), (cont).rend()
#define fast     ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define tc int tt;cin>>tt;while(tt--)
ll x,n;
vector<ll> a(1005);
ll dp[1005][1005][2];
bool recurse(int idx, int cnt, bool div2) {
    if(idx==(n+1)&&cnt!=0){
        return 0;
    }
    if(cnt==0) {
        return div2;
    }
    if(dp[idx][cnt][div2]!=-1)return dp[idx][cnt][div2];
    return dp[idx][cnt][div2]=recurse(idx+1,cnt-1,(a[idx]+div2)%2)|recurse(idx+1,cnt,div2);
}
int main() {
    fast
tc{
    memset(dp,-1,sizeof(dp));
    cin>>n>>x;
    for(int i = 1; i <= n; i++)cin>>a[i];
    cout<<(recurse(1,x,0)?"Yes":"No")<<'\n';
}
}
