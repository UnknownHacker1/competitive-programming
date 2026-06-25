/*
 * IOI '08 P1 - Type Printer  [ioi08p1]
 * Problem:  https://dmoj.ca/problem/ioi08p1
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2022-12-12
 * Language: C++20
 * Runtime:  0.445173839 s     Memory: 51176.0 KB
 * Source:   https://dmoj.ca/src/5115345
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
int children[500010][26];
int dp[500010];
bool End[500010];
int dummyValue;
void insert(const string& s){
    int c = 1;
    for(char ch : s){
        int x = ch - 'a';
        if(!children[c][x]){
            children[c][x]=dummyValue;
            dummyValue++;
        }
        c = children[c][x];
    }
    End[c] = 1;
}
int depth(int n){
    if(dp[n]!=-1)
        return dp[n];
    int mx = 0;
    for(int i = 0; i < 26; i++){
        int c = children[n][i];
        if(c){
            mx=max(mx,depth(c));
        }
    } 
    return dp[n] = mx + 1;
}
vector<char>output;
void dfs(int n){
    if(End[n])output.push_back('P');
    int childWithMaxDep=-1,mxDep=0;
    for(int i = 0; i < 26; i++){
        int c = children[n][i];
        if(c){ 
            int dist=depth(c);
            if(mxDep<dist){
                mxDep=dist;
                childWithMaxDep=i;
            }
        } 
    }
    for(int i = 0; i < 26; i++){
        if(i == childWithMaxDep)continue;
        int c = children[n][i];
        if(c){
            output.push_back(i+'a');
            dfs(c);
            output.push_back('-');
        }
    }
    if(childWithMaxDep!=-1){
        output.push_back(childWithMaxDep+'a');
        dfs(children[n][childWithMaxDep]);
        output.push_back('-');
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ACPLS(); 
    dummyValue = 2; 
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        insert(s);
    }
    depth(1);
    dfs(1);
    while(output.back()=='-')output.pop_back();
    cout<<output.size()<<'\n';
    for(char ch : output)cout<<ch<<'\n';
}