/*
 * CCO '03 P4 - Constrained Permutations  [cco03p4]
 * Problem:  https://dmoj.ca/problem/cco03p4
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2022-11-14
 * Language: C++20
 * Runtime:  0.039942798 s     Memory: 3340.0 KB
 * Source:   https://dmoj.ca/src/5032247
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
    int n,k;
    cin>>n>>k;
    set<pair<int,int>>st;
    for(int i = 0; i < k; i++){
        int x,y;
        cin>>x>>y;
        st.insert({x,y});
    }
    int ans = 0;
    int pos[n+1];
    for(int i = 1; i <= n; i++)pos[i]=i;
    do{
        bool ok = 1;
        for(auto&i:st){
            if(pos[i.first]>pos[i.second]){
                ok=0;break;
            }
        }
        ans+=ok;
    }while(next_permutation(pos+1,pos+n+1));
    cout<<ans<<'\n';
}