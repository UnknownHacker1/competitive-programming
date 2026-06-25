/*
 * Farewell Party  [1081B]
 * Problem:  https://codeforces.com/problemset/problem/1081/B
 * Verdict:  ACCEPTED        Solved: 2021-08-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  61 ms     Memory: 7500 KB
 * Tags:     constructive algorithms, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1081/submission/125243914
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int64_t, null_type,less<int64_t>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int64_t, null_type,less_equal<int64_t>, rb_tree_tag,tree_order_statistics_node_update>
 
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
int64_t POWNOM(int64_t a, int64_t b)
{
	if(b==0) return 1;
    int64_t res = POWNOM(a,b/2);
    if(b&1)
        return (res*res*a);
    return (res*res);
}
ll sum_range2d(ll i, ll j, ll k, ll l, vector<vector<ll>>& vec)
{
    return vec[k][l] - vec[k][j - 1] - vec[i - 1][l] + vec[i - 1][j - 1];
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
double dist(double X1, double Y1, double X2, double Y2)
{
    return sqrt( ( (X1 - X2)*(X1 - X2) ) + ( (Y1-Y2)*(Y1-Y2) ) );
}
bool intersect(pair<ll,ll>p1, pair<ll,ll>p2)
{
	ll x1=p1.first,x2=p1.second,y1=p2.first,y2=p2.second;
    return (x1 >= y1 && x1 <= y2) ||
           (x2 >= y1 && x2 <= y2) ||
           (y1 >= x1 && y1 <= x2) ||
           (y2 >= x1 && y2 <= x2);
}
bool isPrime(ll n)
{
	if(n==2)
		return true;
	if(n%2==0||n==1)
		return false;
    for (ll i = 3; i * i <= n; i+=2) 
    	if (n % i == 0) 
    		return false; 
    return true;
}
ll inverse(ll n)
{
    return POW(n%mod,mod-2);
}
template<typename T1, typename T2>
bool mul_overflow(T1 x, T2 y) { // log(xy)=log(x)+log(y)
    return (log2(x)+log2(y)) >= 64.0;
}
template<typename T1, typename T2>
bool exp_overflow(T1 x, T2 y) { // log(x^y)=ylog(x)
	return y*log2(x)>=64.0;
}
ll sod(ll x){
	ll ret=0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	return ret;
}
ll ceili(ll x,ll y){
    return (x + y - 1) / y;
}
string operator*(const string& a, size_t n){
	string ret;
	for(int i = 0; i < n; i++)ret+=a;
	return ret;
}
void operator*=(string& a, size_t n){
	string cpy=a;
	for(int i = 1; i < n; i++)a+=cpy;
	if(!n)a="";
}
void append(vector<int>&a,const vector<int>&b){
	for(auto&i:b)a.push_back(i);
}
bool isPalindrome(const string& s){
	bool ok = 1;
	for(int i = 0; i <= (int)s.size()/2; i++){
		ok&=(s[i]==s[(int)s.size()-i-1]);
	}
	return ok;
}
bool isPOWB(int64_t a, int64_t b, ll lm){
	int64_t cur=1;
	for(ll i = 0; i <= lm; i++){
		if(cur==a)return true;
		if(i<lm)cur*=b;
	}
	return false;
}
void ACPLS(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
}
 
vector<vector<ll>> C;
void bin_coeff(ll n, ll k)
{
	C=vector<vector<ll>>(n+3,vector<ll>(k+3,0));
    for(int i = 0; i <= min(n,k); i++) C[i][i]=1, C[i][0]=1;
    for(int i = 0; i <= max(n,k); i++) C[i][0]=1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}
vector<int> prime;
void sievePrime(ll n)
{
	prime.resize(n+3,1);
	prime[0]=false;
    prime[1]=false;
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}
template<typename _Cont_Ty>
void pa(_Cont_Ty Cont, bool space = 1){
	for(auto it = std::begin(Cont); it != std::end(Cont); ++it){
		cout<<*it;
		if(space)cout<<' ';
	}
	cout<<'\n';
}
template<typename _It_Ty>
void pa(_It_Ty beg, _It_Ty en, bool space = 1){
	for(auto it = beg; it != en; ++it){
		cout<<*it;
		if(space)cout<<' ';
	}
	cout<<'\n';
}
template<typename _Ty>
_Ty& minref(_Ty& a, _Ty& b){
	if(a<b)return a;
	return b;
}
/// End of BidoTeima legacy functions
#define ALL(x) (x).begin(),(x).end()
#define all(cont) (cont).begin(), (cont).end()
#define rall(cont) (cont).rbegin(), (cont).rend()
#define tc int tt;cin>>tt;while(tt--)
#define sumrange1d(l,r,pref) (l==0?pref[r]:pref[r]-pref[l-1])
int main()
{
	ACPLS();
	int n;
	cin>>n;
	vector<int>occ[n];
	int ans[n],a[n];
	for(int i = 0; i < n; i++){
		cin>>a[i];
		occ[a[i]].push_back(i);
	}
	int cur=1;
	for(int i = 0; i < n; i++){
		if(occ[i].empty())continue;
		int inc=n-i-1;
		for(int j = 0; j < (int)occ[i].size(); j++){
			ans[occ[i][j]]=cur;
			if(j==inc){
				inc+=n-i;
				++cur;
			}
		}
	}
	int freq[n+1]={0};
	for(auto&i:ans){
		++freq[i];
	}
	bool ok=1;
	for(int i = 0; i < n; i++){
		if(freq[ans[i]]!=n-a[i]){
			ok=0;
		}
	}
	if(!ok)
		cout<<"Impossible";
	else{
		cout<<"Possible\n";
		for(auto&i:ans)
			cout<<i<<' ';
	}
}