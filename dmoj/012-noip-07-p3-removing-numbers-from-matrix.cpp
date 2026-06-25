/*
 * NOIP '07 P3 - Removing Numbers from Matrix  [noip07p3]
 * Problem:  https://dmoj.ca/problem/noip07p3
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-01-08
 * Language: C++20
 * Runtime:  2.098348764 s     Memory: 21772.0 KB
 * Source:   https://dmoj.ca/src/5197497
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
#ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
        freopen("input.txt", "r", stdin);
#endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/    
vector< vector < vector <  __int128_t > > > dp(
    83, vector< vector < __int128_t > > (83, vector < __int128_t >(83,  -1000000000000000000000000000)));
int main()
{ 
    ACPLS();     
    int n,m;
    cin>>n>>m;
    ll a[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    __int128_t pw[m + 1];
    pw[1] = 2;
    for(int i = 2; i <= m; i++){
        pw[i] = pw[i - 1] * 2;
    }
    for(int i = 0; i < 83; i++){
        for(int j = 0; j < 83; j++){
            for(int k = 0; k < 83; k++){
                for(int l = 0; l < 83; l++){
                    dp[i][j][k] = -1e18;
                }
            }
        }
    }
    for(int k = 0; k < 83; k++){
        dp[1][m][k] = 0;
    }
    for(int turn = 1; turn <= m; turn++){
        vector< vector < vector <  __int128_t > > > new_dp(
    83, vector< vector < __int128_t > > (83, vector < __int128_t >(83,  -1000000000000000000000000000)));
        for(int l = 1; l <= m; l++){
            for(int r = m; r >= l; r--){
                for(int row = 1; row <= n; row++){
                    new_dp[l + 1][r][row] = max(new_dp[l + 1][r][row],
                    dp[l][r][row] + pw[turn]*a[row][l]);

                    new_dp[l][r - 1][row] = max(new_dp[l][r - 1][row],
                    dp[l][r][row] + pw[turn]*a[row][r]);
                }
            }
        }
        dp = new_dp;
    }
    __int128_t ans = 0;
    for(int row = 1; row <= n; row++){
        __int128_t mx = 0;
        for(int l = 0; l <= m; l++){
            mx=max(mx,dp[l+1][l][row]);
        }
        ans += mx;
    }
    string out;
    do{
        out.push_back(char((ans%10)+'0'));
        ans /= 10;
    } while(ans);
    reverse(out.begin(),out.end());
    cout<<out<<'\n';
}