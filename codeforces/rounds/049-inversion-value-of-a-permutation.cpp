/*
 * Inversion Value of a Permutation  [2145D]
 * Problem:  https://codeforces.com/problemset/problem/2145/D
 * Verdict:  ACCEPTED        Solved: 2025-10-27
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  92 ms     Memory: 400 KB
 * Tags:     constructive algorithms, dfs and similar, dp
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2145/submission/345965200
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1030, inf = 1e18 + 3, mod = 998244353;

int dp[35][35*35];

bool rec(int n, int k){
    if(n == 0){
        return k == 0;
    }
    if(dp[n][k]!=-1)return dp[n][k];
    bool ret = 0;
    for(int p = 1; p <= n; p++){
        ret |= rec(n - p, k - p * (n - p));
    }
    return dp[n][k]=ret;    
}
int ans[35];
void build2(int n, int k, int sum, vector<int>&v){
    if(n == 0) return;
    for(int p = 1; p <= n; p++){
        if(rec(n - p, k - p * (n - p))){
            if(v.empty()){
                cout<<n<<' '<<k<<' '<<sum<<'\n';
                exit(0);    
            }
            ans[sum+p-1] = v.back();
            v.pop_back();
            for(int i = sum; i < sum+p; i++){
                assert(!v.empty());
                ans[i]=v.front();
                v.erase(v.begin());
            }
            build2(n - p, k - p * (n - p), sum + p, v);
            return;
        }
    }
}
void cons(int n, int k, int pos, vector<int> &v)
{
    if(v.size() == 0) return;
    for(int cur = pos; cur <= pos + n - 1; cur++)
    {
        int p = cur - pos + 1;
        if(rec(n - p, k - p * (n - p)))
        {
            ans[cur] = v.back();
            v.pop_back();
            for(int i = pos; i < cur; i++)
            {
                ans[i] = v.front();
                v.erase(v.begin());
            }
            cons(n - p, k - p * (n - p), cur + 1, v);
            return;
        }
    }
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin >> n >> k;
    if(!rec(n, k)){
        cout << "0\n";
        return;
    }
    vector<int>v;
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    cons(n, k, 1, v);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}