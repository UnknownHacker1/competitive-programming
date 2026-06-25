/*
 * Coins  [47B]
 * Problem:  https://codeforces.com/problemset/problem/47/B
 * Verdict:  ACCEPTED        Solved: 2020-12-31
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/47/submission/102912289
 */

#include<bits/stdc++.h>
 
using namespace std;
 
int cnt=0,x;
vector<string> v;
 
int main()
{
   map<char,int> mp;
   mp.insert(pair<char, int>('A',0));
   mp.insert(pair<char, int>('B',0));
   mp.insert(pair<char, int>('C',0));
   string s;
   cin>>s;
   if(s[1]=='>')mp[s[0]]++;
    else mp[s[2]]++;
 
   cin>>s;
   if(s[1]=='>')mp[s[0]]++;
    else mp[s[2]]++;
 
   cin>>s;
   if(s[1]=='>')mp[s[0]]++;
    else mp[s[2]]++;
 
            if(mp['A']==1&&mp['B']==1&&mp['C']==1)
            cout<<"Impossible";
        else{
            if(mp['A']==0)cout<<"A";
            else if(mp['B']==0)cout<<"B";
            else if(mp['C']==0)cout<<"C";
 
            if(mp['A']==1)cout<<"A";
            else if(mp['B']==1)cout<<"B";
            else if(mp['C']==1)cout<<"C";
 
            if(mp['A']==2)cout<<"A";
            else if(mp['B']==2)cout<<"B";
            else if(mp['C']==2)cout<<"C";}
 
 
   return 0;
 
}