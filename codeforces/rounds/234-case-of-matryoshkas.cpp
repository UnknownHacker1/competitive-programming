/*
 * Case of Matryoshkas  [555A]
 * Problem:  https://codeforces.com/problemset/problem/555/A
 * Verdict:  ACCEPTED        Solved: 2021-06-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 4300 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/555/submission/118304345
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
	if(n%2==0)
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
bool isPalindrome(const string& s){
	bool ok = 1;
	for(int i = 0; i <= (int)s.size()/2; i++){
		ok&=(s[i]==s[(int)s.size()-i-1]);
	}
	return ok;
}
void ACPLS(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
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
#define tc int tt;cin>>tt;while(tt--)
// use the slow way that's gonna work instead of
// the fast way you're not sure is gonna work!
int main(){
	ACPLS(); 
	int n,k,ans=0;
	cin>>n>>k;
	vector<vector<int>>partitions;
	for(int i = 0; i < k; i++){
		int m;
		cin>>m;
		int a[m+1];
		for(int j = 1; j <= m; j++)
			cin>>a[j];
		int firstIdx=0;
		for(int j = 1; j+1 <= m; j++){
			if(a[j]+1!=a[j+1]){
				firstIdx=j;
				break;
			}
		}
		if(!firstIdx){
			partitions.push_back(vector<int>(a+1,a+m+1));
			continue;
		}
		vector<int>vc;
		for(int j = 1; j <= firstIdx; j++)
			vc.push_back(a[j]);
		partitions.push_back(vc);
		for(int j = firstIdx+1; j <= m; j++)
			partitions.push_back({a[j]});
		ans+=(m-firstIdx);
	}
	sort(all(partitions),
		[](const vector<int>& a, const vector<int>& b){
			return (*min_element(all(a)))<(*min_element(all(b)));
	});
	vector<int>partitions_sizes;
	for(auto&v:partitions){
		partitions_sizes.push_back((int)v.size());
	}
	for(int i = 0; i+1 < (int)partitions_sizes.size(); i++){
		ans+=partitions_sizes[i+1]*2-1;
		partitions_sizes[i+1]+=partitions_sizes[i];
	}
	cout<<ans;
}