/*
 * Load Testing  [847H]
 * Problem:  https://codeforces.com/problemset/problem/847/H
 * Verdict:  ACCEPTED        Solved: 2021-07-22
 * Language: C++17 (GCC 9-64)
 * Runtime:  46 ms     Memory: 8100 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/847/submission/123279581
 */

/// isA AC
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("-Ofast")
using namespace std;
	  template<
	  typename Key, // Key type
	  typename Mapped, // Mapped-policy
	  typename Cmp_Fn = std::less<Key>, // Key comparison functor
	  typename Tag = __gnu_pbds::rb_tree_tag, // Specifies which underlying data structure to use
	  template<
	  typename Const_Node_Iterator,
	  typename Node_Iterator,
	  typename Cmp_Fn_,
	  typename Allocator_>
	  class Node_Update = __gnu_pbds::null_node_update, // A policy for updating node invariants
	  typename Allocator = std::allocator<char> > // An allocator type
	  class tree;
typedef tree<
int,
__gnu_pbds::null_type,
less<int>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>
ordered_set;
 
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
	ll a[n],pref[n]={0},suff[n]={0};
	for(auto&i:a)cin>>i;
	vector<ll>ap(a,a+n),as(a,a+n);
	for(int i = 1; i < n; i++){
		pref[i]=pref[i-1];
		if(ap[i]<=ap[i-1]){
			pref[i]+=ap[i-1]+1-ap[i];
			ap[i]=ap[i-1]+1;
		}
	}
	for(int i = n-2; i >= 0; i--){
		suff[i]=suff[i+1];
		if(as[i]<=as[i+1]){
			suff[i]+=as[i+1]+1-as[i];
			as[i]=as[i+1]+1;
		}
	}
	ll ans=min(suff[0],pref[n-1]);
	for(int i = 1; i < n-1; i++){
		if(ap[i]>=as[i])
			ans=min(ans,pref[i]+suff[i+1]);
	}
	cout<<ans;
}