/*
 * Mainak and Interesting Sequence  [1726B]
 * Problem:  https://codeforces.com/problemset/problem/1726/B
 * Verdict:  ACCEPTED        Solved: 2022-09-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 400 KB
 * Tags:     bitmasks, constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1726/submission/171080926
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
        #ifndef ONLINE_JUDGE
            freopen("output.txt", "w", stdout);
            freopen("input.txt", "r", stdin);
        #endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()  
int main()
{
    ACPLS("");  
tc{
    int n,m;
    cin>>n>>m;
    if(m<n || ((m%n) % 2 == 1 && n % 2 == 0)){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        int a[n];
        for(int i = 0; i < n; i++)a[i] = m / n;
        if(n % 2 == 0) {
            a[n - 2] += (m % n) / 2;
            a[n - 1] = a[n - 2];
        }
        else{
            a[n - 1] += (m % n);
        }
        for(int i : a)
            cout<<i<<' ';
        cout<<'\n';
    }
}
}   