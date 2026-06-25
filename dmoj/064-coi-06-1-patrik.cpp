/*
 * COI '06 #1 Patrik  [coi06p1]
 * Problem:  https://dmoj.ca/problem/coi06p1
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2023-06-05
 * Language: C++20
 * Runtime:  0.749754082 s     Memory: 8412.0 KB
 * Source:   https://dmoj.ca/src/5574605
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N = 5e5 + 3;
int a[N];
int v[N];
map<int, vector<int>> occ{};
int cnt(int l, int r, int x){
    const vector<int>& v = occ[x];
    return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}  
double f(int n){
    double ret = 0;
    stack<pair<int,int>>st;
    for(int i = n - 1; i >= 0; i--){
        while(st.size() && st.top().first <= a[i]){
            st.pop();
        }
        if(st.size())ret++;
        if(st.size())ret += cnt(i + 1, st.top().second, a[i]) * 0.5;
        else ret += cnt(i + 1, n - 1, a[i]) * 0.5;
        st.push({a[i], i});
    }
    return ret;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);     
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)cin>>a[i],occ[a[i]].push_back(i);
    double ans = 0;
    ans += f(n);
    reverse(a, a + n);
    occ.clear();
    for(int i = 0; i < n; i++)occ[a[i]].push_back(i);
    cout<<ll(ans + f(n));
    return 0;
}