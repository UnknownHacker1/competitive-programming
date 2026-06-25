/*
 * Robot Queries  [1902D]
 * Problem:  https://codeforces.com/problemset/problem/1902/D
 * Verdict:  ACCEPTED        Solved: 2023-12-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  1778 ms     Memory: 20400 KB
 * Tags:     binary search, data structures, dp, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1902/submission/238067898
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
struct Point{
    int x=0,y=0;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
    Point operator+(const Point& other){
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point& other){
        return Point(x - other.x, y - other.y);
    } 
    bool operator<(const Point second){
    return x < second.x;
}
};
bool operator<(const Point first, const Point second){
    return first.x == second.x ? first.y < second.y : first.x < second.x;
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<Point>p(n+1, Point());
    map<Point,vector<int>>occ;
    occ[Point()].push_back(0);
    for(int i = 1; i <= n; i++){
        char ch;
        cin>>ch;
        if(ch=='U'){
            p[i].y=1;
        }
        if(ch == 'D'){
            p[i].y=-1;
        }
        if(ch == 'L'){
            p[i].x=-1;
        }
        if(ch == 'R'){
            p[i].x=1;
        }
        p[i] = p[i] + p[i - 1]; 
        occ[p[i]].push_back(i);
    }  
    while(q--){
        int x,y,l,r;
        cin>>x>>y>>l>>r;  
        Point point(x, y);
        vector<int>&v = occ[point];  
        if(v.size() && (v.front() < l || v.back() >= r)){
            cout<<"YES\n";
            continue; 
        }
        point = p[l - 1] + p[r] - point; 
        vector<int>&v2 = occ[point]; 
        auto it = lower_bound(v2.begin(),v2.end(),l - 1);
        if(it != v2.end() && *it <= r){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
    return 0;
}