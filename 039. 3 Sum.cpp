#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(), arr.end());
	set<vector<int>> res;
	for(int i = 0; i < n; i++){
		int a = i+1, b = n-1;
		while(a < b){
			if(arr[i]+arr[a]+arr[b] == K){
				res.insert({arr[i], arr[a], arr[b]});
				a++;
				b--;
			}else if(arr[i]+arr[a]+arr[b] < K){
				a++;
			}else{
				b--;
			}
		}
	}
	return vector<vector<int>>(res.begin(), res.end());
}
