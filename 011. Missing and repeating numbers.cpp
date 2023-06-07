#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	map<int, int> mp;
	for(auto it: arr){
		mp[it]++;
	}
	int re, mi;
	for(int i = 1; i <= n ;i++){
		if(mp[i] == 0){
			mi = i;
		}
		if(mp[i] > 1){
			re = i;
		}
	}
    return { mi, re };
}
