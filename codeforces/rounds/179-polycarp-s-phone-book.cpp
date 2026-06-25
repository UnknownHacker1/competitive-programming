/*
 * Polycarp's phone book  [858D]
 * Problem:  https://codeforces.com/problemset/problem/858/D
 * Verdict:  ACCEPTED        Solved: 2021-12-01
 * Language: C++20 (GCC 11-64)
 * Runtime:  3822 ms     Memory: 204900 KB
 * Tags:     data structures, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/858/submission/137727703
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
    map<string,int>freq{};
    vector<string>v[n];
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        map<string,bool>vis{};
        for(int j = 0; j < 9; j++){
            string cur;
            for(int k = j; k < 9; k++){
                cur+=s[k];
                freq[cur]+=(!vis[cur]);
                vis[cur]=1;
                v[i].push_back(cur);
            }
        }
    }
    for(int i = 0; i < n; i++){
        string ans;
        for(int j = 0; j < (int)v[i].size(); j++){
            if(freq[v[i][j]]==1){
                if(ans.empty())
                    ans=v[i][j];
                else if(v[i][j].size()<ans.size())
                    ans=v[i][j];
            }
        }
        cout<<ans<<'\n';
    }
}
