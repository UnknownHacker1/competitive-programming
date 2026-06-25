/*
 * Luna Likes Love  [103148B]
 * Problem:  Gym/ICPC contest 103148 - problem B
 * Verdict:  ACCEPTED        Solved: 2023-12-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  249 ms     Memory: 7800 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103148/submission/236503453
 */

#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;   
const int N = 1e6 + 5;
int bit[N];
void add(int i, int x){
    for(i++; i < N; i += i & (-i))
        bit[i] += x;
}
int get(int i){
    int ret = 0;
    for(i++; i; i -= i & (-i))
        ret += bit[i];
    return ret;
}  
int query(int l, int r){
    return l == 0? get(r) : get(r) - get(l - 1);
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);  
    int n;
    cin>>n;
    pair<int,int>a[n+1];
    fill(a,a+n+1,make_pair(-1,-1));
    for(int i = 0; i < 2 * n; i++){
        int x;
        cin>>x; 
        if(a[x].first==-1)a[x].first=i;
        else a[x].second=i;
    }
    sort(a+1,a+n+1,[](pair<int,int>&p1,pair<int,int>&p2){
        return p1.second-p1.first < p2.second-p2.first;
    });
    for(int i = 0; i < 2 * n; i++){
        add(i, 1);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += query(a[i].first, a[i].second) - 1;
        add(a[i].first, -1);
        add(a[i].second, -1);
    }
    cout<<ans;
    return 0;
}