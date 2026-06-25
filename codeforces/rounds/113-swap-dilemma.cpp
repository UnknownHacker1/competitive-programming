/*
 * Swap Dilemma  [1983D]
 * Problem:  https://codeforces.com/problemset/problem/1983/D
 * Verdict:  ACCEPTED        Solved: 2025-03-26
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  390 ms     Memory: 7800 KB
 * Tags:     constructive algorithms, data structures, divide and conquer, greedy, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1983/submission/312622534
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 3;
int bit[N],n;
int sum(int r){
    int ret = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
}
void add(int i){
    for(; i < n; i |= (i + 1)) bit[i]++;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int t;
    cin>>t;
    while(t--){ 
        memset(bit,0,sizeof(bit));
        //int n;
        cin>>n;
        int a[n],b[n];
        map<int,int>mp,mpb;
        for(int i = 0; i < n; i++)cin>>a[i],mp[a[i]],bit[i]=0;
        for(int i = 0; i < n; i++)cin>>b[i],mpb[b[i]];
        bool ok = 1;
        for(auto it = mp.begin(), it2 = mpb.begin();  it != mp.end(); it++,it2++){
            if(*it != *it2){
                ok = 0;
                break;
            }
        }
        if(!ok){
            cout<<"nO\n";
            continue;
        }
        int idx = 0;
        for(auto&it:mp)it.second=idx++;
        idx=0;
        for(auto&it:mpb)it.second=idx++;
        int inv = 0;
        for(int i = n - 1; i >= 0; i--){
            inv += sum(mp[a[i]]);
            add(mp[a[i]]);
        }
        for(int i = 0; i < n; i++)bit[i] = 0;
        for(int i = n - 1; i >= 0; i--){
            inv -= sum(mp[b[i]]);
            add(mp[b[i]]);
        }
        inv=abs(inv);
        cout<<((inv&1)?"nO\n":"yEs\n");
    }
    return 0;
}