/*
 * Borya and Hanabi  [443C]
 * Problem:  https://codeforces.com/problemset/problem/443/C
 * Verdict:  ACCEPTED        Solved: 2023-08-17
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     bitmasks, brute force, constructive algorithms, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/443/submission/219378974
 */

#include <bits/stdc++.h>
using namespace std;
int mat[5][5];
int mp[255];
bool check(int mask1, int mask2){ 
    bool marked_num[5]{},marked_col[5]{};
    bool flag=0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(!mat[i][j])continue;
            int r = -1; 
            if(!((1<<i) & mask1)){
                if(marked_num[j])return 0;
                marked_num[j]=i+1;
                ++r;
            }
            if(!((1<<j) & mask2)){
                if(marked_col[i])return 0;
                marked_col[i]=j+1;
                ++r;
            }
            if(r==1){
                if(flag)return 0;
                flag=1;
            }
        }
    }  
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mp['R']=0;
    mp['G']=1;
    mp['B']=2;
    mp['Y']=3;
    mp['W']=4;
    int n;
    cin>>n; 
    for(int i = 0; i < n; i++){
        string s; 
        cin>>s;
        mat[mp[s[0]]][s[1]-'1']=1;
    }
    int ans = 10;
    for(int mask1 = 0; mask1 < (1 << 5); mask1++){
        for(int mask2 = 0; mask2 < (1 << 5); mask2++){
            if(check(mask1,mask2)){
                ans=min(ans,__builtin_popcount(mask1)+__builtin_popcount(mask2));
            }
        }
    }
    cout<<ans;
    return 0;
}