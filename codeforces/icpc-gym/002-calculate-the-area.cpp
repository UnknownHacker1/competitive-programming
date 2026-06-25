/*
 * Calculate The Area  [102397B]
 * Problem:  Gym/ICPC contest 102397 - problem B
 * Verdict:  ACCEPTED        Solved: 2021-02-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/102397/submission/107135272
 */

#include <bits/stdc++.h>
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
    return (POW(n%mod,mod-2));
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
bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
/// End of BidoTeima legacy functions
#define sinDegrees(x) sin((x) * PI / 180.0)
#define cosDegrees(x) cos((x) * PI / 180.0)
#define tanDegrees(x) tan((x) * PI / 180.0)
#define atanDegrees(x) atan(x)* 180.0 / PI
#define asinDegrees(x) asin(x)* 180.0 / PI
#define flush fflush(stdout)
#define ULL unsigned long long
#define LL long long
#define LD long double
#define EPS 0.000000001
#define MOD 1000000007
//#define endl '\n'
#define ALL(x) x.begin(),x.end()
#define MAXN (int)1e5+5
#define PI acos(-1)
//#pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
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
struct edge{
    int to;
    ll cost;
    edge(){}
    edge(int _to, ll _cost){
        to=_to;
        cost=_cost;
    }
    bool operator <  (const edge & b ) const{
        if(cost > b.cost)return true;
        return false;
    }
};
int main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ///bin_coeff();
    ///inverse -> (x % mod * inverse(y) % mod) %mod
    ///sievePrime(1000005);
    fast
    ll n;
    cin>>n;
    cout<<n<<' '<<1;
    return 0;
}
