/*
 * Ceil Divisions  [1469D]
 * Problem:  https://codeforces.com/problemset/problem/1469/D
 * Verdict:  ACCEPTED        Solved: 2021-12-04
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 4200 KB
 * Tags:     brute force, constructive algorithms, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1469/submission/137981435
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int f(int n, int x){
    int ret=0;
    while(n>1){
        n=(n+x-1)/x;
        ret++;
    }
    return ret;
}
int main()
{
    ACPLS();   
tc{
    int n;
    cin>>n;
    if(n==3){
        cout<<"2\n3 2\n3 2\n";
        continue;
    } 
    int TheChosenOne=-1,TheChosenOneRes=1e9;
    for(int i = 2; i < n; i++){
        if(i==2&&f(n,i)+1<TheChosenOneRes){
            TheChosenOne=i;
            TheChosenOneRes=f(n,i)+1;
        }
        else if(f(n,i)+f(i,2)<TheChosenOneRes){
            TheChosenOne=i;
            TheChosenOneRes=f(n,i)+f(i,2);
        }
    }
    vector<pair<int,int>>ans;
    for(int i = 3; i < n; i++){
        if(i!=TheChosenOne){
            ans.push_back({i,i+1});
        }
    }
    int lg2=f(TheChosenOne,2),lgi=f(n,TheChosenOne);
    for(int i = 0; i < lgi; i++){
        ans.push_back({n,TheChosenOne});
    }
    if(TheChosenOne!=2){
        for(int i = 0; i < lg2; i++){
            ans.push_back({TheChosenOne,2});
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i.first<<' '<<i.second<<'\n';
}
}
