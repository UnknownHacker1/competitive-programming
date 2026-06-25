/*
 * String LCM  [1473B]
 * Problem:  https://codeforces.com/problemset/problem/1473/B
 * Verdict:  ACCEPTED        Solved: 2021-01-14
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     brute force, math, number theory, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1473/submission/104313784
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
#define f first
#define s second
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
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
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
//End
int32_t main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        string s, t;
        cin>>s>>t;
        string minstr;
        if(s.size()<t.size()) minstr=s;
        else minstr = t;
        bool ok = false;
        for(int i = minstr.size(); i >= 1; i--) {
            string sub = minstr.substr(0, i);
            string create;
            ll ap1 = 0, ap2=0;
            bool found1=false,found2=false;
            while(create.size()<=s.size()) {
                create+=sub;
                ++ap1;
                if(create==s) {
                    found1=true;
                    break;
                }
            }
            create="";
            while(create.size()<=t.size()) {
                create+=sub;
                ++ap2;
                if(create==t) {
                    found2=true;
                    break;
                }
            }
            string ans;
            if(found1&&found2) {
                ll sz = (ap1*ap2)/gcd(ap1, ap2);
                for(int i = 1; i <= sz; i++) {
                    ans+=sub;
                }
                if(ans.size()%s.size()==0&&ans.size()%t.size()==0) {
                    cout<<ans<<'\n';
                    ok = true;
                    break;
                }
            }
        }
        if(!ok) cout<<-1<<'\n';
    }
    return 0;
}
