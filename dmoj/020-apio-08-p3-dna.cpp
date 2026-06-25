/*
 * APIO '08 P3 - DNA  [apio08p3]
 * Problem:  https://dmoj.ca/problem/apio08p3
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-08-26
 * Language: C++20
 * Runtime:  0.217519304 s     Memory: 30528.0 KB
 * Source:   https://dmoj.ca/src/5734861
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,int>dna{};
string code = "ACGT";
const int M = 5e4 + 3;
int m,k;
ll r;
char s[M];
ll dp[5][12][M];
ll rec(int idx, int form, int prev){
    if(form < 0)
        return 0;
    if(idx == m){
        return 1;
    }
    if(dp[prev][form][idx]!=-1)
        return dp[prev][form][idx];
    ll ret = 0;
    if(s[idx] == 4){
        for(int i = 0; i < 4; i++){  
            if(i >= prev){
                ret += rec(idx + 1, form, i);
            }
            else{
                ret+=rec(idx + 1, form-1, i); 
            }
        }
    }else if(s[idx] >= prev){
        ret = rec(idx + 1, form, s[idx]);
    }
    else{
        ret = rec(idx + 1, form - 1, s[idx]);
    } 
    return dp[prev][form][idx] = ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dna['A']=0;
    dna['C']=1;
    dna['G']=2;
    dna['T']=3;
    dna['N']=4;
    cin>>m>>k>>r; 
    r--;
    for(int i = 0; i < m; i++){
        cin>>s[i];
        s[i]=dna[s[i]];
    }  
    int cur=1; 
    for(int i = 0; i < m; i++){
        if(s[i]!=4){
            if(s[i] < s[i-1])cur++; 
        }
        else{
            int c;
            for(c = 0; c < 4; c++){
                if(c < s[i-1]){
                    if(r < rec(i+1,k-cur-1,c))break;
                    else r -= rec(i+1,k-cur-1,c);
                }else{  
                    if(r < rec(i+1,k-cur,c))break;
                    else r-=rec(i+1,k-cur,c);
                }
            }
            if(c<s[i-1])cur++;
            s[i]=c;
        }
    }
    assert(r==0);
    for(int i = 0; i < m; i++){
        cout<<code[s[i]];
    }
    return 0;
}