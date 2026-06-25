/*
 * Beautiful XOR  [2162C]
 * Problem:  https://codeforces.com/problemset/problem/2162/C
 * Verdict:  ACCEPTED        Solved: 2025-10-19
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     bitmasks, constructive algorithms, greedy
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2162/submission/344576433
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int msba=0;
        for(int i = 29; i >= 0; i--){
            if(a&(1<<i)){
                msba=i;
                break;
            }
        }
        int msbb=0;
        for(int i = 29; i >= 0; i--){
            if(b&(1<<i)){
                msbb=i;
                break;
            }
        }
        if(msba < msbb){
            cout<<"-1\n";
            continue;
        }
        vector<int>ans;
        for(int i = 0; i < 30; i++){
            if((a & (1 << i)) != (b & (1 << i))){
                ans.push_back(1 << i);
            }
        }
        cout << (int)ans.size() << '\n';
        for(int i:ans)cout<<i<<' ';
        cout << '\n';
    }

    return 0;
}