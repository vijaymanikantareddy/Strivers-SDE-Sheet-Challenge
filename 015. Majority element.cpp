#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int, int> mp;
	for(int i = 0 ; i < n ; i++){
		mp[arr[i]]++;
	}
	int mx = -1;
	int res = -1;
	for(auto it: mp){
		if(it.second > mx){
			res = it.first;
			mx = it.second;
		}
	}
	if(mx > (n/2)){
		return res;
	}
	return -1;
	
}
