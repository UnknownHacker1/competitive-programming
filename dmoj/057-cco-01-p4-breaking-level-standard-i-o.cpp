/*
 * CCO '01 P4 - Breaking Level (Standard I/O)  [cco01p4io]
 * Problem:  https://dmoj.ca/problem/cco01p4io
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2022-12-16
 * Language: C++20
 * Runtime:  0.035129514 s     Memory: 3448.0 KB
 * Source:   https://dmoj.ca/src/5125635
 */

#include <iostream>
#include <cassert>
using namespace std;
int H = 1;
bool testing(int t) {
    return t >= H;
}
int GetN() {
    cout << "GetN" << endl;
    int N;
    cin >> N;
    return N;
}
int GetD() {
    cout << "GetD" << endl;
    int D;
    cin >> D;
    return D;
}
bool Drop(int t) {
    cout << "Drop " << t << endl;
    bool b;
    cin >> b;
    return b;
}
void Decide(int t) {
    cout << "Decide " << t << endl;
    exit(0);
}
int main()
{ 
    int N = GetN();
    int D = GetD(); 
    int l = 1;
    int r = D;
    int jump = D - 1;
    while (!Drop(r)) {
        l = r + 1;
        r += jump;
        --jump;
    }
    for (int i = l; i < r; i++) {
        if (Drop(i))Decide(i);
    }
    Decide(r);
    return 0;
}