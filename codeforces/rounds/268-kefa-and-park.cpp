/*
 * Kefa and Park  [580C]
 * Problem:  https://codeforces.com/problemset/problem/580/C
 * Verdict:  ACCEPTED        Solved: 2021-01-18
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 8300 KB
 * Tags:     dfs and similar, graphs, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/580/submission/104721865
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
bool intersect(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
bool isPrime(ll n) {
    for(ll i = 2; i * i <= n; i++) if(n%i==0) return false;
    return true;
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
vector<vector<int>> adj(100005);
vector<bool> vis(100005, false);
vector<bool> hascat(100005, false);
ll ans, n, m;
int dfs(int v, int counter) {
    if(vis[v]) return 0;
    vis[v]=true;
    if(adj[v].size()==1&&v!=1) ++ans;
    if(hascat[v]) ++counter;
    //cout<<"VISITED "<<v<<'\n';
    for(int i = 0; i < (int)adj[v].size(); i++) {
        if(!vis[adj[v][i]]) {
            if(hascat[adj[v][i]]) {
                if(counter<m) dfs(adj[v][i], counter);
                else continue;
            }
            else dfs(adj[v][i], 0);
        }
    }
    return 0;
}
int32_t main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    fast
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        bool b;
        cin>>b;
        hascat[i]=b;
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout<<ans;
    return 0;
}
