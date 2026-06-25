/*
 * Array Destruction  [1474C]
 * Problem:  https://codeforces.com/problemset/problem/1474/C
 * Verdict:  ACCEPTED        Solved: 2021-12-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  702 ms     Memory: 900 KB
 * Tags:     brute force, constructive algorithms, data structures, greedy, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1474/submission/138582647
 */

/// isA AC
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
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
tc{
    int n;
    cin>>n;
    n*=2;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n),reverse(b,b+n);
    vector<pair<int,int>>ans;
    int initial=-1;
    for(int first = 1; first < n; first++){
        unordered_map<int,int>freq{};
        for(int i = 0; i < n; i++){
            ++freq[a[i]];
        }
        vector<pair<int,int>>res;
        --freq[b[0]],--freq[b[first]];
        res.push_back({b[0],b[first]});
        int x=b[0];
        for(int i = 1; i < n && res.size() < n/2; i++){
            if(b[i]==x)continue;
            auto&ref1=freq[b[i]];
            auto&ref2=freq[x-b[i]];
            if(b[i]!=x&&ref1>0&&ref2>0){
                if(x!=2*b[i]||(x==2*b[i]&&ref1>1)){
                    --ref1;
                    --ref2;
                    res.push_back({b[i],x-b[i]});
                    x=b[i];
                }
            }
        }
        if(res.size()==n/2){
            ans=res;
            initial=b[0]+b[first];
            break;
        }
    }
    if(initial==-1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<initial<<'\n';
        for(auto i:ans)
            cout<<i.first<<' '<<i.second<<'\n';
    }
}
}
