/*
 * Double Perspective  [2129A]
 * Problem:  https://codeforces.com/problemset/problem/2129/A
 * Verdict:  ACCEPTED        Solved: 2025-09-03
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  125 ms     Memory: 100 KB
 * Tags:     constructive algorithms, dp, dsu, graphs, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2129/submission/336704680
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    { 
        int n;
        cin >> n;
        vector<array<int, 3>> v;
        for(int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, -y, i});
        }
        sort(v.begin(), v.end());
        int s = v[0][0], e = 0;
        vector<int> ind;
        for(int i = 0; i < n; i++)
        {
            v[i][1] *= -1;
            int l = v[i][0], r = v[i][1], j = v[i][2];
            if(l > e) 
            {
                s = l, e = r;
                ind.push_back(j);
                continue;
            }
            if(r > e)
            {
                e = r;
                ind.push_back(j);
            }
        }
        cout << ind.size() << '\n';
        for(int i : ind) cout << i << " ";
        cout << '\n';
    }
    return 0;
}