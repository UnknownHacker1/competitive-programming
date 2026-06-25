/*
 * Coach  [300B]
 * Problem:  https://codeforces.com/problemset/problem/300/B
 * Verdict:  ACCEPTED        Solved: 2021-06-01
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 200 KB
 * Tags:     brute force, dfs and similar, graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/300/submission/118094647
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
	string tmp=s;
	reverse(tmp.begin(),tmp.end());
	return tmp==s;
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
vector<int> adj[49];
bool vis[49];
vector<set<int>>ans;
set<int>component;
void dfs(int node){
	if(vis[node])
		return;
	vis[node]=1;
	component.insert(node+1);
	for(auto child : adj[node]){
		dfs(child);
	}
}
int main() {
    ACPLS();
    int n,m;
    cin>>n>>m;
   	for(int i = 0; i < m; i++){
   		int a,b;
   		cin>>a>>b;
   		--a,--b;
   		adj[a].push_back(b);
   		adj[b].push_back(a);
   	}
   	for(int i = 0; i < n; i++){
   		if(vis[i]==0&&adj[i].size()>0){
   			dfs(i);
   			ans.push_back(component);
   			component.clear();
   		}
   	}
   	set<int>rem;
   	for(int i = 1; i <= n; i++){
   		rem.insert(i);
   	}
   	for(auto&v:ans){
   		for(auto&i:v){
   			rem.erase(i);
   		}
   	}
   	for(auto&v:ans){
   		while(v.size()<3&&rem.size()){
   			v.insert(*rem.begin());
   			rem.erase(rem.begin());
   		}
   	}
   	int cnt=0;
   	string out;
   	for(auto&v:ans){
   		int idx = 0;
   		for(auto&i:v){
   			out+=to_string(i),out+=' ';
   			++cnt;
   			if(idx+1==(int)v.size())out+='\n';
   			++idx;
   		}
   	}
   	while(cnt<n&&rem.size()){
   		out+=to_string(*rem.begin()),out+=' ';
   		rem.erase(rem.begin());
   		++cnt;
   		if(cnt%3==0)out+='\n';
   	}
   	for(auto&v:ans){
   		if(v.size()!=3){
   			cout<<-1;
   			return 0;
   		}
   	}
   	if(cnt<n)cout<<-1;
   	else cout<<out;
}