/*
 * Did We Get Everything Covered?  [1924A]
 * Problem:  https://codeforces.com/problemset/problem/1924/A
 * Verdict:  ACCEPTED        Solved: 2025-01-08
 * Language: C++20 (GCC 13-64)
 * Runtime:  327 ms     Memory: 0 KB
 * Tags:     constructive algorithms, dp, greedy, shortest paths, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1924/submission/300100935
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    cin >> s;
    bool dp[27][26] {0};
    int lst[27];
    int afterLst[27]{};
    int suff[m];
    memset(lst,-1,sizeof(lst));
    set<int>st;
    for(int i=0; i<k; i++){
        dp[0][i] = 1;
        st.insert(i);
    }
    for(int i = m - 1; i >= 0; i--){
        auto it = st.find(s[i]-'a');
        if(it != st.end()) st.erase(it);
        if(!st.empty()) suff[i] = *st.begin();
        else suff[i] = -1;
    }
    for(int i=0; i<m; i++){
        if((s[i]-'a') >= k) continue;
        int toSet;
        for(int j=1; j<=n; j++){
            if(dp[j][s[i]-'a']==1)continue; 
            bool good = 1;
            for(int l=0; l<k; l++){
                if(!dp[j-1][l]){  
                    good = 0;
                    break;
                }
            }
            if(good && lst[j - 1] == -1){
                //cout << j - 1 << ' ' << i << '\n';
                lst[j - 1] = i == 0? 0 : s[i - 1] - 'a'; // cuz dp[j - 1] has just become all 1s at (i - 1)..
                // afterLst[j] should be set to any letter that does not exist in [i, m - 1]
                // I precomputed that above
                afterLst[j - 1] = suff[i];
                toSet=j;
                break;
            }
        }
        dp[toSet][s[i]-'a']=1;
    }
    bool found=0;
    for(int i = 1; i <= n; i++){
        bool badSize=0;
        for(int j = 0; j < k; j++){
            if(!dp[i][j])badSize=1;
        }
        if(badSize){
            found=1;
            cout<<"NO\n";
            //cout<<i<<'\n';
            for(int j = 1; j < i - 1; j++)cout<<char(lst[j]+'a');
            if(i - 1 != 0) { if(lst[i - 1] == -1) cout << s.back();
            else cout << char(lst[i - 1]+'a'); }
            for(int j = 0; j < n - i + 1; j++){
                cout<<char(afterLst[i - 1]+'a');
            }
            cout<<'\n';
            break;
        }
    }
    if(!found) cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}