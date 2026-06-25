/*
 * NOIP '05 P1: Scholarship  [noip05p1]
 * Problem:  https://dmoj.ca/problem/noip05p1
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-12-23
 * Language: C++20
 * Runtime:  0.032980528 s     Memory: 3444.0 KB
 * Source:   https://dmoj.ca/src/5144764
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
int calc(int avg, int eval_res, char studentLeader, char isWestern, int researchPapers){
    int ret = 0;
    if(avg > 80 && researchPapers){
        ret += 8000;
    }
    if(avg > 85 && eval_res > 80){
        ret += 4000;
    }
    if(avg > 90){
        ret += 2000;
    }
    if(avg > 85 && isWestern == 'Y'){
        ret += 1000;
    }
    if(studentLeader == 'Y' && eval_res > 80){
        ret += 850;
    }
    return ret;
}
int main()
{
    ACPLS();      
    int n;
    cin>>n;
    string best="";
    int ans = -1;
    int total = 0;
    for(int i = 0; i < n; i++){
        string name;
        int avg, eval_res, researchPapers;
        char studentLeader, isWestern; 
        cin>>name>>avg>>eval_res>>studentLeader>>isWestern>>researchPapers;
        int x = calc(avg,eval_res,studentLeader,isWestern,researchPapers);
        if(x>ans){
            ans = x;
            best = name;
        }
        total += x;
    }
    cout<<best<<'\n'<<ans<<'\n'<<total<<'\n';
}