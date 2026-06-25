/*
 * Colorful Field  [79B]
 * Problem:  https://codeforces.com/problemset/problem/79/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 200 KB
 * Tags:     implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/79/submission/103179525
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if(p1.f==p2.f) return p1.s<=p2.s;
    return p1.f<p2.f;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    map<pair<int, int>, bool> freq_waste{};
    pair<int, int> a[k];
    for(int i = 0; i < k; i++) {
        cin>>a[i].f>>a[i].s;
        freq_waste[{a[i].f, a[i].s}] = 1;
    }
    sort(a, a+k, cmp);
    while(q--) {
        int x,y;
        cin>>x>>y;
        if(freq_waste[{x, y}]) {cout<<"Waste\n"; continue;}
        int wastes = lower_bound(a, a+k, make_pair(x,y), cmp)-a;
        y+=((x-1)*m);
        int num=y-wastes;
        if(num%3==1) cout<<"Carrots\n";
        else if(num%3==2) cout<<"Kiwis\n";
        else cout<<"Grapes\n";
    }
    return 0;
}