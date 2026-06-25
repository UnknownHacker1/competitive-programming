/*
 * Educational DP Contest AtCoder C - Vacation  [dpc]
 * Problem:  https://dmoj.ca/problem/dpc
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-02-12
 * Language: C++20
 * Runtime:  0.288281353 s     Memory: 16504.0 KB
 * Source:   https://dmoj.ca/src/4324345
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
#define f first
#define s second
#define fast     ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
//End
const int MAX = 1e5+5;
vector<ll> arr(MAX, -1);
ll memo[3][MAX];
int n;
ll recurse(char ch, int i, vector<ll>& A, vector<ll>& B, vector<ll>& C) {
    if(i>=n)return 0;
    if(memo[ch-65][i] != -1) {
        return memo[ch-65][i];
    }
    if(ch=='A') {
        ll b=recurse('B',i+1,A,B,C);
        ll c=recurse('C',i+1,A,B,C);
        arr[i]=A[i]+max(b,c);
        //cout<<"arr["<<i+1<<"]: "<<arr[i]<<'\n';
        return memo[ch-65][i] = arr[i];
    }
    else if(ch=='B') {
        ll a=recurse('A',i+1,A,B,C);
        ll c=recurse('C',i+1,A,B,C);
        arr[i]=B[i]+max(a,c);
        //cout<<"arr["<<i+1<<"]: "<<arr[i]<<'\n';
        return memo[ch-65][i] = arr[i];
    }
    else {
        ll a=recurse('A',i+1,A,B,C);
        ll b=recurse('B',i+1,A,B,C);
        arr[i]=C[i]+max(a,b);
        //cout<<"arr["<<i+1<<"]: "<<arr[i]<<'\n';
        return memo[ch-65][i] = arr[i];
    }
}
int main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ///bin_coeff();
    fast
    cin>>n;
    vector<ll> A(n), B(n), C(n);
    for(int i = 0; i < n; i++) cin>>A[i]>>B[i]>>C[i];
    memset(memo,-1,sizeof(memo));
    ll ans = 0;
    for(char ch = 'A'; ch <= 'C'; ch++) ans = max(ans, recurse(ch, 0, A, B, C));
    cout<<ans;
    return 0;
}