/*
 * Card Game  [2104C]
 * Problem:  https://codeforces.com/problemset/problem/2104/C
 * Verdict:  ACCEPTED        Solved: 2025-08-21
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  328 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms, games, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2104/submission/334737846
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool beat(int x, int y, int n){
    return (x>y && !(x==n&&y==1)) || (x==1&&y==n);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int>A,B;
        for(int i = 1; i <= n; i++){
            char ch;
            cin>>ch;
            if(ch=='A')A.insert(i);
            if(ch=='B')B.insert(i);
        } 
        while(!A.empty() && !B.empty()){ 
            // alice turn 
            // does she have a card that can beat every card bob has?
            // yes -> play it 
            // else, play her minimum except if it is 1 and bob has an n
            // if that is the case, play her 2nd minimum 
            // except if its the only iterator (obviously lol :p)
            int alice=-1;
            for(auto&i:A){
                bool ok = 1;
                for(auto&j:B){
                    if(!beat(i,j,n)){
                        ok = 0;
                    }
                }
                if(ok){
                    alice=i;
                }
            }
            if(alice==-1){
                if(*A.begin() == 1 && B.find(n) != B.end() && A.size() > 1){
                    alice = *next(A.begin());
                }
                else alice = *A.begin();
            }
            // as for bob.......
            // if he has a card greater than alice's the only logical choice would be to play it otherwise play his minimum
            // again, EXCEPT IF that minimum == 1 and bob has an n, in that case then he shall play the 2nd minimum
            // obviously except if he only has 1 left lmao..
            int bob = -1;
            if(B.upper_bound(alice) != B.end()){
                bob = *B.upper_bound(alice);
            } 
            else if(alice == n && B.find(1) != B.end()){
                bob = 1;
            }
            if(bob == -1){
                if(*B.begin() == 1 && A.find(n) != A.end() && B.size() > 1){
                    bob = *next(B.begin());
                }
                else bob = *B.begin();
            }
            // cout<<alice<<' '<<bob<<'\n';
            if(beat(alice,bob,n)){
                A.insert(bob);
                B.erase(B.find(bob));
            }
            else{
                B.insert(alice);
                A.erase(A.find(alice));
            }
        }
        cout<<(A.empty()?"Bob":"Alice")<<'\n';
    }
    return 0;
}