/*
 * Polycarp and String Transformation  [1560E]
 * Problem:  https://codeforces.com/problemset/problem/1560/E
 * Verdict:  ACCEPTED        Solved: 2022-07-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  124 ms     Memory: 3500 KB
 * Tags:     binary search, implementation, sortings, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1560/submission/163959799
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
int main()
{
	ACPLS();
tc{
	string t;
	cin>>t;
	string order; 
	int freq[26]={0};
	for(int i = (int)t.size()-1; i >= 0; i--){
		if(!freq[t[i]-'a']){
			order.push_back(t[i]);
		}
		freq[t[i]-'a']++;
	}
	reverse(order.begin(),order.end());
	int curfreq[26]={0};
	string s;
	for(int i = 0; i < (int)t.size(); i++){
		if(curfreq[t[i]-'a']==freq[t[i]-'a']/(find(order.begin(),order.end(),t[i])-order.begin()+1))
			break;
		curfreq[t[i]-'a']++;
		s+=t[i];
	}
	string re = s;
	for(int i = 0; i < (int)order.size(); i++){
		for(int j = 0; j < (int)s.size(); j++){
			bool ok = 1;
			for(int k = 0; k <= i; k++){
				ok&=s[j]!=order[k];
			}
			if(ok)re+=s[j];
		}
	}
	if(re!=t)
		cout<<"-1\n";
	else cout<<s<<' '<<order<<'\n';
}
}
