/*
 * DMOPC '21 Contest 5 P3 - Permutations & Primes  [dmopc21c5p3]
 * Problem:  https://dmoj.ca/problem/dmopc21c5p3
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2023-01-10
 * Language: C++20
 * Runtime:  7.410448777 s     Memory: 4400.0 KB
 * Source:   https://dmoj.ca/src/5204014
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
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
    while (tttttt--)/*end
*/    
bool isPrime[(int)1e5 + 3];
vector<int>primes;
void build(int n){
    for(int i = 2; i <= n; i++)isPrime[i]=1;
    for(ll i = 2; i <= n; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= n; j+=i){
                isPrime[j] = 0;;
            }
        }
    }
}
int n;
bool dp[(int)1e5+3]={0};
int main()
{ 
    //ACPLS();   
    build(1e5);
    dp[0] = 1;
    for(int i = 1; i <= 1e5; i++){
        for(int prime : primes){
            if(prime>=i)break;
            if(!dp[i - prime]){
                dp[i] = 1;
                break;
            }
        }
    }
tc{ 
    cin>>n;
    vector<int>ans={-1};
    if(dp[n]){
        ans.clear();
        for(int i = 1; i <= n; i++){
            ans.push_back(i);
        }
    }     
    else if(n>=2&&dp[n-1]){
        ans.clear();
        for(int i = 1; i <= n - 2; i++){
            ans.push_back(i);
        }
        ans.push_back(n);
        ans.push_back(n-1);
    }
    else if(n>=3&&dp[n-2]){
        ans.clear();
        for(int i = 1; i <= n-3; i++){
            ans.push_back(i);
        }
        ans.push_back(n);
        ans.push_back(n-2);
        ans.push_back(n-1);
    }
    for(int i = 0; i < (int)ans.size(); i++){
        cout<<ans[i]<<(i + 1 == (int)ans.size()?'\n':' ');
    } 
}
}