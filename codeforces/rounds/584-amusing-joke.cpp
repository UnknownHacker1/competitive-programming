/*
 * Amusing Joke  [141A]
 * Problem:  https://codeforces.com/problemset/problem/141/A
 * Verdict:  ACCEPTED        Solved: 2020-09-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     implementation, sortings, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/141/submission/93283896
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int freq_arr_shuffled[91] = {0};
int freq_arr_names[91] = {0};
void test_case()
{
    string s1, s2;
    cin>>s1>>s2;
    s1+=s2;
    string shuffled;
    cin>>shuffled;
    if((int)shuffled.length() == (int)s1.length()) {
        for(int i = 0; i < (int)shuffled.length(); i++) {
            ++freq_arr_shuffled[shuffled[i]];
        }
        for(int i = 0; i < (int)s1.length(); i++) {
            ++freq_arr_names[s1[i]];
        }
        for(char i = 'A'; i <= 'Z'; i++) {
            if(freq_arr_shuffled[i] != freq_arr_names[i]) {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
    }
    else cout << "NO";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
