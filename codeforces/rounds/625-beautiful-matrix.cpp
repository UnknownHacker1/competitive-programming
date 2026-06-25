/*
 * Beautiful Matrix  [263A]
 * Problem:  https://codeforces.com/problemset/problem/263/A
 * Verdict:  ACCEPTED        Solved: 2021-02-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  60 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/263/submission/107116798
 */

#include <iostream>


using namespace std;

int main()
{
    int arr[5][5];
    int i = 0,j = 0, pos1, pos2, ans;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (arr[i][j] == 1) {
                pos1=i;
                pos2=j;
            }
        }
    }
    ans = abs(3 - (pos1+1)) + abs(3 - (pos2+1));
    cout << ans;
    return 0;
}