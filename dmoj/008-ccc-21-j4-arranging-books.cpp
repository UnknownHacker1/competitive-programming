/*
 * CCC '21 J4 - Arranging Books  [ccc21j4]
 * Problem:  https://dmoj.ca/problem/ccc21j4
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-01-07
 * Language: C++20
 * Runtime:  0.592359298 s     Memory: 51108.0 KB
 * Source:   https://dmoj.ca/src/4186613
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
    while (tttttt--)99

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
int h(char ch){
    if(ch=='L')
        return 0;
    if(ch=='M')
        return 1;
    return 2;
}
int main()
{
    ACPLS();
    string s,s2;
    cin>>s;s2=s;
    set<int>occ[3],occ2[3];
    int cnt[3]={0};
    for(int i = 0; i < (int)s.size(); i++){
        s[i]=h(s[i]);
        s2[i]=s[i];
        occ[s[i]].insert(i);
        occ2[s[i]].insert(i);
        cnt[s[i]]++;
    }
    int ans=0;
    for(int i = 0; i < cnt[0]; i++){
        if(s[i]!=0){
            auto it = occ[0].upper_bound(s[i]==1?cnt[0]+cnt[1]-1:cnt[0]+cnt[1]+cnt[2]-1);
            if(it==occ[0].begin())
                it=occ[0].lower_bound(i);
            else it=prev(it);
            occ[s[i]].erase(i);
            occ[s[i]].insert(*it);
            swap(s[i],s[*it]);
            occ[0].erase(*it);
            occ[0].insert(i);
            ans++;
        }
    } 
    for(int i = cnt[0]; i-cnt[0]<cnt[1]; i++){
        if(s[i]!=1){
            auto it = occ[1].upper_bound(cnt[0]+cnt[1]+cnt[2]-1);
            if(it==occ[1].begin())
                it=occ[1].lower_bound(i);
            else it=prev(it);
            occ[s[i]].erase(i);
            occ[s[i]].insert(*it);
            swap(s[i],s[*it]);
            occ[1].erase(*it);
            occ[1].insert(i);
            ans++;
        }        
    }
    int ans2=0;


    for(int i = 0; i < cnt[0]; i++){
        if(s2[i]!=0){
            auto it = occ2[0].lower_bound(s2[i]==1?cnt[0]:cnt[0]+cnt[1]);
            if(it==occ2[0].end())
                it=occ2[0].lower_bound(i);
            occ2[s2[i]].erase(i);
            occ2[s2[i]].insert(*it);
            swap(s2[i],s2[*it]);
            occ2[0].erase(*it);
            occ2[0].insert(i);
            ans2++;
        }
    } 
    for(int i = cnt[0]; i-cnt[0]<cnt[1]; i++){
        if(s2[i]!=1){
            auto it = occ2[1].lower_bound(cnt[0]+cnt[1]);
            if(it==occ2[1].end())
                it=occ2[1].lower_bound(i);
            occ2[s2[i]].erase(i);
            occ2[s2[i]].insert(*it);
            swap(s2[i],s2[*it]);
            occ2[1].erase(*it);
            occ2[1].insert(i);
            ans2++;
        }        
    }
    cout<<min(ans,ans2);
}