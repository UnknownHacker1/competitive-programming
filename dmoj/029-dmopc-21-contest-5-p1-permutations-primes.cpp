/*
 * DMOPC '21 Contest 5 P1 - Permutations & Primes  [dmopc21c5p1]
 * Problem:  https://dmoj.ca/problem/dmopc21c5p1
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2022-02-19
 * Language: C++20
 * Runtime:  1.220099135 s     Memory: 7336.0 KB
 * Source:   https://dmoj.ca/src/4359991
 */

/// isA AC
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
bool isPrime(int x){
    if(x==1)return 0;
    for(int i = 2; i * i <= x; i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int main()
{
    ACPLS();
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        cout<<'\n';
        return 0;
    }
    if(n<=3){
        cout<<-1;cout<<'\n';
        return 0;
    }
    vector<int>even,odd;
    for(int i = 1; i <= n; i++){
        if(i&1)odd.push_back(i);
        else even.push_back(i);
    }
    for(int i = 0; i < (int)even.size(); i++){
        if(!isPrime(even[i]+odd[0])){
            swap(even[i],even.back());
            break;
        }
    }
    for(int i = 0; i < (int)odd.size(); i++){
        if(!isPrime(odd[i]+even.back())){
            swap(odd[i],odd[0]);
            break;
        }
    }
    if(isPrime(even.back()+odd[0])){
        cout<<-1;cout<<'\n';
    }
    else{
        for(int x:even)cout<<x<<' ';
        int sadlol=odd.back();
        odd.pop_back();
        for(int x:odd)cout<<x<<' ';
        cout<<sadlol;cout<<'\n';
    }
}