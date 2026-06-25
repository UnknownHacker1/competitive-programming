/*
 * IOI '07 P4 - Miners  [ioi07p4]
 * Problem:  https://dmoj.ca/problem/ioi07p4
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-11-12
 * Language: C++20
 * Runtime:  0.221033073 s     Memory: 3428.0 KB
 * Source:   https://dmoj.ca/src/5026348
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
ll dp[4][4][4][4];
int f(int x, int y, int z) {
    if(x == 3) x = z;
    if(y == 3) y = z;
    if (x == y && y == z) 
        return 1;
    if (x == y || y == z || x == z) 
        return 2;
    return 3;
}
int main()
{
    ACPLS("");  
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto&i:s){
        if(i=='M')i='0';
        if(i=='F')i='1';
        if(i=='B')i='2';
    } 

    for(int i = 0; i <= n; i++){
        for(int m1_a = 0; m1_a <= 3; m1_a++){
            for(int m1_b = 0; m1_b <= 3; m1_b++){
                for(int m2_a = 0; m2_a <= 3; m2_a++){
                    for(int m2_b = 0; m2_b <= 3; m2_b++){
                        dp[m1_a][m1_b][m2_a][m2_b]=-1e9;
                    }
                }
            }
        }
    } 
    dp[3][3][3][3]=0;
    for(int i = 1; i <= n; i++){
        ll new_dp[4][4][4][4];
        for(int m1_a = 0; m1_a <= 3; m1_a++){
            for(int m1_b = 0; m1_b <= 3; m1_b++){
                for(int m2_a = 0; m2_a <= 3; m2_a++){
                    for(int m2_b = 0; m2_b <= 3; m2_b++){
                        new_dp[m1_a][m1_b][m2_a][m2_b]=-1e9;
                    }
                }
            }
        }
        for(int m1_a = 0; m1_a <= 3; m1_a++){
            for(int m1_b = 0; m1_b <= 3; m1_b++){
                for(int m2_a = 0; m2_a <= 3; m2_a++){
                    for(int m2_b = 0; m2_b <= 3; m2_b++){
                        int c = s[i-1] - '0';
                        new_dp[m1_b][c][m2_a][m2_b]=max(new_dp[m1_b][c][m2_a][m2_b], dp[m1_a][m1_b][m2_a][m2_b] + f(m1_a,m1_b,c)); 
                        new_dp[m1_a][m1_b][m2_b][c]=max(new_dp[m1_a][m1_b][m2_b][c], dp[m1_a][m1_b][m2_a][m2_b] + f(m2_a,m2_b,c)); 
                    }
                }
            }
        }
        for(int i = 0; i <= 3; i++)for(int j = 0; j <= 3; j++)
            for(int k = 0; k <= 3; k++)for(int l = 0; l <= 3; l++)dp[i][j][k][l] = new_dp[i][j][k][l];
    }
    ll ans = 0;
    for(int m1_a = 0; m1_a <= 3; m1_a++){
        for(int m1_b = 0; m1_b <= 3; m1_b++){
            for(int m2_a = 0; m2_a <= 3; m2_a++){
                for(int m2_b = 0; m2_b <= 3; m2_b++){
                     ans=max(ans,dp[m1_a][m1_b][m2_a][m2_b]);
                }
            }
         }
    }
    cout<<ans;
}