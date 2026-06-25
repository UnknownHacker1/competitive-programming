/*
 * Restoring Permutation  [1315C]
 * Problem:  https://codeforces.com/problemset/problem/1315/C
 * Verdict:  ACCEPTED        Solved: 2022-02-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1315/submission/145842668
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
int main()
{
    ACPLS();
tc{
    int n;
    cin>>n;
    int b[n+1];
    int a[2*n+1];
    set<int>st;
    for(int i = 1; i <= 2*n; i++){
        st.insert(i);
    }
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        st.erase(b[i]);
    }
    bool can = 1;
    for(int i = 1; i <= n; i++){
        auto sec = st.lower_bound(b[i]);
        if(sec==st.end()){
            can=0;
            break;
        }
        a[2*i-1]=b[i];
        a[2*i]=*sec;
        st.erase(sec);
    }
    if(!can){
        cout<<"-1\n";
        continue;
    }
    for(int i = 1; i <= n; i++){
        if(min(a[2*i-1],a[2*i])!=b[i]){
            can=0;
            break;
        }
    }
    if(!can){
        cout<<"-1\n";
    }else{
        for(int i = 1; i <= 2*n; i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}
}


