/*
 * Longest Array Deconstruction  [1575L]
 * Problem:  https://codeforces.com/problemset/problem/1575/L
 * Verdict:  ACCEPTED        Solved: 2025-02-22
 * Language: C++17 (GCC 7-32)
 * Runtime:  1296 ms     Memory: 256600 KB
 * Tags:     data structures, divide and conquer, dp, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1575/submission/307293088
 */

#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("-malign-natural")
#pragma GCC optimize("Ofast,fast-math")
#define POOL_SIZE 250 * 1024 * 1024
char memoryPool[POOL_SIZE + 1];  // Pre-allocated memory pool
size_t poolIndex = 0;  // Tracks the next available memory slot


void* operator new(size_t size) { 
    if (poolIndex + size > POOL_SIZE) {
        return malloc(size); // Not enough space in pool
    }
    void* ptr = &memoryPool[poolIndex];
    poolIndex += size;
    return ptr;
}



using namespace std; 

using ll = long long; 
const int N = 2e5 + 5;
int n;
int ql,qr,qlX,qrX,iX,i,x;
struct Node {
    int value;
    Node* left, *right;
    Node(){
        value=0;
        left=right=nullptr;
    }
    int queryY(int l, int r){
        if(l > r || r < ql || l > qr){
            return 0;
        }
        if(ql <= l && r <= qr){
            return value;
        }
        int mid = (l + r) >> 1;
        int ret = 0;
        if(left && l <= mid && mid >= ql && l <= qr){
            ret = left->queryY(l, mid);
        }
        if(right && mid + 1 <= r && r >= ql && mid + 1 <= qr){
            ret=max(ret, right->queryY(mid + 1, r));
        }
        return ret;
    }
    void updateY(int l, int r){
        if(l == r){
            value = x;
            return;
        }
        int mid = (l + r) >> 1; 
        if(l<=mid && l <= i && i <= mid){
            if(!left)left = new Node();
            left->updateY(l, mid);
        }
        if(mid + 1 <= r && mid + 1 <= i && i <= r){
            if(!right)right = new Node();
            right->updateY(mid + 1, r);
        }
        value = max(left?left->value:0, right?right->value:0);
    }
};
struct NodePar{
    Node* child;
    NodePar *left, *right;
    NodePar(){
        child=nullptr;
        left=right=nullptr;
    }
    int queryX(int l, int r){
        if(l > r || r < qlX || l > qrX){
            return 0;
        }
        if(qlX <= l && r <= qrX){
            return child?child->queryY(0, n):0;
        }
        int mid = (l + r) >> 1;
        return max(left?left->queryX(l, mid):0, right?right->queryX(mid + 1, r):0);
    }
    void updateX(int l, int r){
        if(l > iX || r < iX) return;
        if(l != r){
            int mid = (l + r) >> 1;
            if(l <= mid && l <= iX && mid >= iX){
                if(!left) left = new NodePar();
                left->updateX(l, mid);
            }
            if(mid + 1 <= r && mid + 1 <= iX && r >= iX){
                if(!right) right = new NodePar();
                right->updateX(mid + 1, r);
            }
        } 
        if(!child) child = new Node();
        child->updateY(0, n);
    }
}; 

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    cin >> n;
    int a[n];
    for(auto& i : a) cin >> i;
    int ans = 0; 
    int sz = n;
    NodePar* root = new NodePar(); 
    for(int I = 0; I < n; I++){ 
        if(a[I] > I + 1) continue; // impossible no matter how
        int strt = a[I] - I + sz - 1;
        qlX=strt,qrX=sz,ql=0,qr=a[I]-1;
        int X = root->queryX(0, sz);
        // cout << "at " << i << " is " << x << " before\n";
        x=X+1;
        ans = max(ans, x);
        iX=strt,i=a[I];
        root->updateX(0, sz);
        // cout << "can start at " << i << '\n';
        //updateX(strt, a[i], 1, 0, sz, 0);
        //ans = max(ans, 1);
    }
    cout << ans;
	return 0;
}
