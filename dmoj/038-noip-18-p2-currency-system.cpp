/*
 * NOIP '18 P2 - Currency System  [noip18p2]
 * Problem:  https://dmoj.ca/problem/noip18p2
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2022-11-11
 * Language: C++20
 * Runtime:  0.936866482 s     Memory: 3356.0 KB
 * Source:   https://dmoj.ca/src/5023792
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
    ACPLS("");  
tc{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a,a+n);
    bitset<26000>can;
    int ans = 0; 
    can[0]=1;
    for(int i = 0; i < n; i++){
        ans += !can[a[i]];
        can[a[i]] = 1;
        for(int j = 0; j <= 25000; j++){
            if(can[j]){
                for(int k = 0; k < n && j + a[i] * k <= 25000; k++){
                    can[j + a[i] * k] = 1;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
}