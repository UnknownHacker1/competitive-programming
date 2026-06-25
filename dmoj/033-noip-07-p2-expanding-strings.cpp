/*
 * NOIP '07 P2 - Expanding Strings  [noip07p2]
 * Problem:  https://dmoj.ca/problem/noip07p2
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2023-01-08
 * Language: C++20
 * Runtime:  0.035262085 s     Memory: 3392.0 KB
 * Source:   https://dmoj.ca/src/5197435
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

int main()
{ 
    ACPLS();     
    int p1, p2, p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    for(int i = 0; i < (int)s.size(); i++){
        cout<<s[i];
        if(i + 2 >= (int)s.size())continue;
        bool isletter = isalpha(s[i]);
        if(s[i]=='-')continue;
        if(s[i + 1] == '-' && isletter == bool(isalpha(s[i + 2])) && s[i + 2] > s[i]){
            string toReplace;
            for(char ch = s[i] + 1; ch < s[i + 2]; ch++){
                char toAdd = ch;
                if(p1 == 2 && isalpha(ch)){
                    toAdd=toupper(toAdd);
                }
                if(p1 == 3){
                    toAdd='*';
                }
                for(int j = 0; j < p2; j++){
                    toReplace.push_back(toAdd);
                }
            }
            if(p3 == 2)reverse(toReplace.begin(),toReplace.end());
            cout<<toReplace;
            i++;
        }
    }
}