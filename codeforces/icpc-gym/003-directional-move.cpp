/*
 * Directional Move  [102942A]
 * Problem:  Gym/ICPC contest 102942 - problem A
 * Verdict:  ACCEPTED        Solved: 2021-01-27
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 500 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/102942/submission/105585291
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
/// BidoTeima legacy functions
using ll = long long;
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
    ch=tolower(ch);
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
int main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ///bin_coeff();
    fast
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll o=0,z=0;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='0')++o;
            else ++z;
        }
        ll diff=abs(o-z);
        char a[4]={'E','S','W','N'};
        char a2[4]={'E','N','W','S'};
        if(z>o) {
            cout<<a2[diff%4]<<'\n';
        }
        else {
            cout<<a[diff%4]<<'\n';
        }
    }
    return 0;
}
