/*
 * Football  [96A]
 * Problem:  https://codeforces.com/problemset/problem/96/A
 * Verdict:  ACCEPTED        Solved: 2020-09-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/96/submission/93284865
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void test_case()
{
    string s;
    cin>>s;
    int count = 1;
    for(int i = 0; i < (int)s.length()-1; i++) {
        if(s[i] == s[i+1]) count++;
        else count = 1;
        if(count == 7) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
