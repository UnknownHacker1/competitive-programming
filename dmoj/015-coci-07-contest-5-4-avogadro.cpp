/*
 * COCI '07 Contest 5 #4 Avogadro  [coci07c5p4]
 * Problem:  https://dmoj.ca/problem/coci07c5p4
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2022-12-17
 * Language: C++20
 * Runtime:  0.176314076 s     Memory: 21736.0 KB
 * Source:   https://dmoj.ca/src/5128146
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
void f(int v, int cur_idx, int lmao){
    if(v < 0){
        cout<<cur_idx<<' '<<lmao;
        exit(0);
    }
}
int main()
{
    ACPLS(); 
    int n,ans=0,x;
    cin>>n; 
    vector<int>allOcc[3][n + 1];
    int freq[3][n + 1];
    for(int i = 0; i < 3; i++)for(int j = 1; j <= n; j++){
        freq[i][j]=0;
    }
    int a[3][n];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin>>x;
            a[i][j]=x;      
            allOcc[i][x].push_back(j);
            ++freq[i][x];
        }
    }
    bool isErased[n]={0};
    for(int lmao = 0; lmao < 10; lmao++)for(int i = 1; i <= n; i++){
        assert(freq[0][i]>=0);
        assert(freq[1][i]>=0);
        assert(freq[2][i]>=0);
        if(freq[0][i]&&freq[1][i]&&freq[2][i])continue;
        int res = 0;
        for(int j = 0; j < 3; j++){
            for(int v : allOcc[j][i]){
                if(isErased[v])continue;
                ++res;
                isErased[v] = 1;
                --freq[0][a[0][v]];
                --freq[1][a[1][v]];
                --freq[2][a[2][v]];
            }
        }
        ans += res;
    }
    vector<int>vec[3];
    for(int i = 0; i < n; i++){
        if(!isErased[i]){
            vec[0].push_back(a[0][i]);
            vec[1].push_back(a[1][i]);
            vec[2].push_back(a[2][i]);
        }
    }
    if(ans == 0 && (vec[0] != vec[1] || vec[1] != vec[2]))ans=1;
    cout<<ans<<'\n';
}