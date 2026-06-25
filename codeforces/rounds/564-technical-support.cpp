/*
 * Technical Support  [1754A]
 * Problem:  https://codeforces.com/problemset/problem/1754/A
 * Verdict:  ACCEPTED        Solved: 2022-10-23
 * Language: C++20 (GCC 11-64)
 * Runtime:  0 ms     Memory: 0 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1754/submission/177670240
 */

/*
ID: BidoTeima
LANG: C++11
TASK: Izbori
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

int main()
{
    ACPLS("");
tc{
    int n;
    string s;
    cin>>n>>s;
    int x = 0;
    bool ok = 1;
    for(int i = 0; i < n; i++){
        if(s[i]=='Q')x--;
        else x++;
        if(x>0)x=0;
    }
    cout<<(x>=0?"Yes\n":"No\n");
}
}