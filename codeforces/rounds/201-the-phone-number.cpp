/*
 * The Phone Number  [1017C]
 * Problem:  https://codeforces.com/problemset/problem/1017/C
 * Verdict:  ACCEPTED        Solved: 2021-11-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 1000 KB
 * Tags:     constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1017/submission/134243375
 */

#include<bits/stdc++.h> // Made by Bido and Nakeeb
using namespace std;
long long cil(long long x,long long i)
{
    return (x+(x%i))/i;
}
int main()
{
    int n,ans=39746287364732,x=1;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(ans>=(cil(n,i)+i))
        {
            ans=cil(n,i)+i;
            if(ans)
            x=i;
        }
    }
    long long curr=n-x+1,mn=23974697236;
    for(int i=0;i<n/x;i++)
    {
        for(int j=0;j<x;j++)
        {
            cout<<curr++<<' ';
            mn=min(mn,curr-1);
        }
        curr-=x*2;
    }
    for(int i=1;i<mn;i++)
        cout<<i<<' ';
}
