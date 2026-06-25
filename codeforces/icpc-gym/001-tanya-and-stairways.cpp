/*
 * Tanya and Stairways  [104637J]
 * Problem:  Gym/ICPC contest 104637 - problem J
 * Verdict:  ACCEPTED        Solved: 2024-07-19
 * Language: C++20 (GCC 13-64)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/104637/submission/271420429
 */

#include <bits/stdc++.h> 
using namespace std;  
using ll = long long;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int>ans;
    for(int i = 1; i < n; i++){
        if(a[i] == 1){
            ans.push_back(a[i - 1]);
        }
    }
    ans.push_back(a[n-1]);
    cout<<(int)ans.size()<<'\n';
    for(int i : ans) cout << i << ' ';
    return 0;  
}