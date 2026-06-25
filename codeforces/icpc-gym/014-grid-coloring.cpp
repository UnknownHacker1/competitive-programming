/*
 * Grid Coloring  [101652W]
 * Problem:  Gym/ICPC contest 101652 - problem W
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345437949
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    
const int N = 35;

char grid[N][N];

int m,n;

ll dp[N][N];


ll rec(int i, int bCnt){ 
    if(i == n){  
        return 1;
    }
    if(dp[i][bCnt] != -1)  return dp[i][bCnt];
    ll ret = 0;
    int firstR=m, lastB=-1;
    
    for(int j = 0; j < m; j++){
        if(grid[j][i] == 'R'){
            firstR = min(firstR, j);
        }
        else if(grid[j][i] == 'B'){
            lastB = j;
        }
    } 
    // [lastB + 1, firstR]
    for(int x = lastB + 1; x <= min(firstR, bCnt); x++){ 
        ret += rec(i + 1, x);
    }
    return dp[i][bCnt] = ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   

    memset(dp,-1,sizeof(dp));

    cin >> m >> n;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout << rec(0, m);
    return 0;
}
