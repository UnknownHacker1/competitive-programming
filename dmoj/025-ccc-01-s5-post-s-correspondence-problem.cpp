/*
 * CCC '01 S5 - Post's Correspondence Problem  [ccc01s5]
 * Problem:  https://dmoj.ca/problem/ccc01s5
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2022-11-15
 * Language: C++20
 * Runtime:  0.51456867 s     Memory: 3356.0 KB
 * Source:   https://dmoj.ca/src/5035293
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
vector<string>X,Y;
bool rec(int idx, string a, string b){
    if(idx == -1)return 0;
    if(a.size()&&a==b)return 1;
    for(int i = 0; i < (int)X.size(); i++){
        if(rec(idx-1,a+X[i],b+Y[i]))return 1;
    }
    return 0;
}
void build(int idx, string a, string b, vector<int>& ans){
    if(a.size()&&a==b)return;
    for(int i = 0; i < (int)X.size(); i++){
        if(rec(idx-1,a+X[i],b+Y[i])){
            ans.push_back(i+1);
            build(idx-1,a+X[i],b+Y[i],ans);
            return;
        }
    }
}
int main()
{
    ACPLS("");   
    int m,n;
    cin>>m>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        X.push_back(s);
    }
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        Y.push_back(s);
    }
    if(!rec(m-1,"","")){
        cout<<"No solution.";
        return 0;
    }
    vector<int>ans;
    build(m-1,"","",ans);
    cout<<ans.size()<<'\n';
    for(int i : ans)
        cout<<i<<'\n';
}