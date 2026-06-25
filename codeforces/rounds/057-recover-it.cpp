/*
 * Recover it!  [1176D]
 * Problem:  https://codeforces.com/problemset/problem/1176/D
 * Verdict:  ACCEPTED        Solved: 2022-07-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  171 ms     Memory: 36500 KB
 * Tags:     dfs and similar, graphs, greedy, number theory, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1176/submission/163033987
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename _Type, typename _Cmp = less<_Type>>
using ordered_set = tree<_Type, null_type, _Cmp, rb_tree_tag,tree_order_statistics_node_update>;
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
int biggestdiv[2750132];
int p[2750132];
int freq[2750132];
void sieve(){
    int count = 1;
    for(ll i = 2; i <= 2750131; i++){
        if(!biggestdiv[i]){
            biggestdiv[i]=1;
            for(ll j = i * i; j <= 2750131; j+=i){
                if(!biggestdiv[j]){
                    biggestdiv[j]=j/i;
                }
            }
            p[i]=count++;
        } 
    }
}
int main()
{
    ACPLS();    
    sieve();
    int n;
    cin>>n;
    vector<int>v;
    for(int i = 0; i < 2*n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        freq[x]++;
    }
    sort(v.begin(),v.end(),greater<int>());
    vector<int>a;
    for(int i = 0; i < (int)v.size() && (int)a.size() < n; i++){
        if(!freq[v[i]])continue;
        if(p[v[i]]!=0){
            freq[p[v[i]]]--; 
            freq[v[i]]--;
            a.push_back(p[v[i]]);
        }
        else{
            freq[biggestdiv[v[i]]]--;
            freq[v[i]]--;
            a.push_back(v[i]);
        }
    }
    for(int i:a)cout<<i<<' ';
}