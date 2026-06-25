/*
 * Beautiful Paintings  [651B]
 * Problem:  https://codeforces.com/problemset/problem/651/B
 * Verdict:  ACCEPTED        Solved: 2022-02-07
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/651/submission/145589217
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
    int n;
    cin>>n;
    int freq[1005]={0};
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        freq[x]++;
    } 
    vector<int>v;
    for(int i = 1; i <= 1000 && (int)v.size()<n; i++){
        if(freq[i]>0){
            freq[i]--;
            v.push_back(i);
        }
        if(i==1000)i=0;
    } 
    int ans=0;
    for(int i = 0; i+1 < n; i++){
        if(v[i+1]>v[i])ans++;
    }
    cout<<ans;
}


