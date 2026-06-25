/*
 * Three Parts of the Array  [1006C]
 * Problem:  https://codeforces.com/problemset/problem/1006/C
 * Verdict:  ACCEPTED        Solved: 2021-01-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 3200 KB
 * Tags:     binary search, data structures, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1006/submission/105172170
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
/// BidoTeima legacy functions
typedef long long ll;
ll POW(ll a, ll b) {
   ll res = 1;
   while(b > 0) {
    if(b%2==1) res*=a;
    a*=a;
    b/=2;
   }
   return res;
}
ll sum_range2d(ll i, ll j, ll k, ll l, vector<vector<ll>>& sum) {
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
ll gcd(ll a, ll b) {
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll dist(ll X1, ll Y1, ll X2, ll Y2) {
    return sqrt( POW(X1-X2, 2) + POW(Y1-Y2,2) );
}
bool intersect(pair<ll, ll> p1, pair<ll, ll> p2) {
  ll x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
bool isPrime(ll n) {
    for(ll i = 2; i * i <= n; i++) if(n%i==0) return false;
    return true;
}
const ll maxn = 105;
ll C[maxn + 1][maxn + 1];
void bin_coeff()
{
    C[0][0] = 1;
    for (ll n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (ll k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}
/*vector<bool> prime(10000005, true);
void sievePrime(ll n)
{
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
#define f first
#define s second
#define fast     ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
//End
int32_t main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ///bin_coeff();
    fast
    ll ans = 0;
    int n;
    cin>>n;
    ll d[n];
    for(int i = 0; i < n; i++) cin>>d[i];
    ll prefix[n+1]={0};
    for(int i = 1; i <= n; i++) {
        prefix[i]=prefix[i-1]+d[i-1];
    }
    int i = 1, j = n;
    while(i < j) {
        if(prefix[i]<prefix[n]-prefix[j-1]) {
            ++i;
        }
        else if(prefix[n]-prefix[j-1]<prefix[i]) {
            --j;
        }
        else {
            ans=max(ans, prefix[i]);
            ++i;
        }
    }
    cout<<ans;
    return 0;
}
