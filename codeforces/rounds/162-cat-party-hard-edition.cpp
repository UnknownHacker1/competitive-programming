/*
 * Cat Party (Hard Edition)  [1163B2]
 * Problem:  https://codeforces.com/problemset/problem/1163/B2
 * Verdict:  ACCEPTED        Solved: 2021-05-09
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 5000 KB
 * Tags:     data structures, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1163/submission/115823870
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
    if(b==0) return 1;
    a%=mod;
    int64_t res = POW(a,b/2);
    if(b&1)
        return (res%mod*res%mod*a%mod)%mod;
    return (res%mod*res%mod)%mod;
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
int sti(int i, set<int>&st){
	auto it = st.begin();
	while(i--)++it;
	return *it;
}
int main() {
    fast
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int freq[(int)1e5+5]={0};
    int freqfreq[(int)1e5+5]={0};
    int a[n];
    int ans=1;
    set<int>st;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        auto it=st.find(freq[a[i]]);
        --freqfreq[freq[a[i]]];
        if(it!=st.end()){
            if(freqfreq[freq[a[i]]]<=0)st.erase(it);
        }
        ++freqfreq[++freq[a[i]]];
        st.insert(freq[a[i]]);
        if(st.size()==1){
        	if(freqfreq[sti(0,st)]==1||sti(0,st)==1)ans=i+1;
        }
        if(st.size()==2){
        	if(sti(1,st)-1==sti(0,st)&&freqfreq[sti(1,st)]==1){
        		ans=i+1;
        	}
        	if(sti(0,st)==1&&freqfreq[sti(0,st)]==1){
        		ans=i+1;
        	}
        }
    }
    cout<<ans;
}
