/*
 * Hills And Valleys  [1467B]
 * Problem:  https://codeforces.com/problemset/problem/1467/B
 * Verdict:  ACCEPTED        Solved: 2021-01-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  109 ms     Memory: 4700 KB
 * Tags:     brute force, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1467/submission/103827443
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;
int a[N], n;

int isValley(int i) {
    return (i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1]);
}

int isHill(int i) {
    return (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]);
}

int solveTestCase() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int is[n] = {};
    int s = 0;
    for (int i = 1; i < n - 1; i++) {
        if (isHill(i) || isValley(i))
            is[i] = 1, s++;
    }

    int ans = s;
    for (int i = 1; i < n - 1; i++) {
        int temp = a[i];
        a[i] = a[i - 1];
        ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
        a[i] = a[i + 1];
        ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
        a[i] = temp;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solveTestCase();
}