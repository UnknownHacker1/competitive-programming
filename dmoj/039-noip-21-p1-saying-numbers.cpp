/*
 * NOIP '21 P1 - Saying Numbers  [noip21p1]
 * Problem:  https://dmoj.ca/problem/noip21p1
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-02-13
 * Language: C++20
 * Runtime:  0.626790508 s     Memory: 10484.0 KB
 * Source:   https://dmoj.ca/src/5326168
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
vector<int>v;
bitset<15000003>notValid{};
bool has7(int x){
    while(x){
        if(x%10==7)return 1;
        x/=10;
    }
    return 0;
}
int main()
{
    ACPLS();   
    for(int i = 1; i <= 1.1e7; i++){
        if(notValid[i]==0&&has7(i)){
            for(int j = i; j <= 1.1e7; j+=i){
                notValid[j]=1;
            }
        }
        if(!notValid[i])v.push_back(i);
    }
tc{
    int x;
    cin>>x;
    if(notValid[x])cout<<"-1\n";
    else cout<<*upper_bound(v.begin(),v.end(),x)<<'\n';
}
}