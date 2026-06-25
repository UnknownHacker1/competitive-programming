/*
 * Verify Password  [1976A]
 * Problem:  https://codeforces.com/problemset/problem/1976/A
 * Verdict:  ACCEPTED        Solved: 2025-03-09
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     implementation, sortings, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1976/submission/309670081
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  
const int N = 2e5 + 3; 

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>letters,digits;
        bool ok = 1;
        for(int i = 0; i < n; i++){
            char ch;
            cin>>ch;
            if(isdigit(ch)){
                if(letters.size()) ok = 0;
                digits.push_back(ch);
            } else letters.push_back(ch);
        }
        if(!is_sorted(letters.begin(),letters.end()) || !is_sorted(digits.begin(),digits.end())) ok = 0;
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}
