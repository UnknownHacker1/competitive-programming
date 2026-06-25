/*
 * Adventurers  [2046C]
 * Problem:  https://codeforces.com/problemset/problem/2046/C
 * Verdict:  ACCEPTED        Solved: 2025-02-24
 * Language: C++17 (GCC 7-32)
 * Runtime:  1015 ms     Memory: 9700 KB
 * Tags:     binary search, data structures, greedy, sortings, ternary search, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2046/submission/307596366
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
const int N = 1e5 + 3;
int st[N << 2][2],szX,szY; 
void update(int i, int x, bool b, int l, int r, int node){
    if(l > r || i < l || i > r) return;
    if(l == r){
        st[node][b] += x;
        return;
    }
    int mid = (l + r) >> 1;
    update(i, x, b, l, mid, (node << 1) + 1), update(i, x, b, mid + 1, r, (node << 1) + 2);
    st[node][b] = st[(node << 1) + 1][b] + st[(node << 1) + 2][b];
} 
int query(int k, bool b, int l, int r, int node){
    if(l > r || st[node][b] < k) return -1;
    if(l == r){
        return l;
    }
    int mid = (l + r) >> 1;
    if(st[(node << 1) + 1][b] >= k)
        return query(k, b, l, mid, (node << 1) + 1);
    return query(k - st[(node << 1) + 1][b], b, mid + 1, r, (node << 1) + 2); 
}
int query2(int ql, int qr, bool b, int l, int r, int node){
    if(l > r || l > qr || r < ql) return 0;
    if(ql <= l && r <= qr) return st[node][b];
    int mid = (l + r) >> 1;
    return query2(ql, qr, b, l, mid, (node << 1) + 1) + query2(ql, qr, b, mid + 1, r, (node << 1) + 2);
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  

    int t;
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;
        for(int i = 0; i <= (n << 2); i++) st[i][0] = st[i][1] = 0; 
        map<int,int>mpX,mpY;
        int x[n],y[n];
        for(int i = 0; i < n; i++){
            cin>>x[i]>>y[i];
            mpX[x[i]],mpY[y[i]];
        }
        szX = (int)mpX.size();
        szY = (int)mpY.size();
        int cur = 0; 
        for(auto&it:mpX) it.second = cur++;
        cur = 0;
        for(auto&it:mpY) it.second = cur++;
        vector<int>occ[szY];
        for(int i = 0; i < n; i++){
            x[i]=mpX[x[i]];
            y[i]=mpY[y[i]];
            occ[y[i]].push_back(x[i]);
        }
        for(int i = 0; i < szY; i++){
            for(int idx : occ[i])
                update(idx, 1, 1, 0, szX - 1, 0);
        }
        int ans = 0, bestX = 0, bestY = 0;
        for(int i = 1; i < szY; i++){
            for(int idx : occ[i - 1]){
                update(idx, 1, 0, 0, szX - 1, 0);
                update(idx, -1, 1, 0, szX - 1, 0);
            }
            int lo = 1, hi = n / 4, mid;
            while(lo <= hi){
                mid = (lo + hi) >> 1;
                int bst = query(mid, 0, 0, szX - 1, 0);
                if(bst != -1){
                    int sc = query(mid, 1, 0, szX - 1, 0);
                    if(sc == -1) bst = -1;
                    else bst = max(bst, sc);
                }
                //cout << "at " << i << "best is " << bst << '\n';
                if(bst != -1 && bst + 1 < szX && 
                min(query2(bst + 1, szX - 1, 0, 0, szX - 1, 0), query2(bst + 1, szX - 1, 1, 0, szX - 1, 0)) >= mid){
                    //assert(bst > 0);
                    if(mid > ans){
                        ans = mid;
                        bestX = bst + 1;
                        bestY = i;
                    }
                    lo = mid + 1;
                } else hi = mid - 1;
            }
        }
        cout << ans << '\n';
        auto itX = mpX.begin(), itY = mpY.begin();
        while(bestX--) ++itX;
        while(bestY--) ++itY;
        cout << itX->first << ' ' << itY->first << '\n';
    }

	return 0;
}
