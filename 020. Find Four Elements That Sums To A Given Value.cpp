#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int a = j+1, b = n-1;
            while(a < b){
                if(arr[i]+arr[j]+arr[a]+arr[b] == target){
                    a++;
                    b--;
                    return "Yes";
                }
                else if(arr[i]+arr[j]+arr[a]+arr[b] < target){
                    a++;
                }else{
                    b--;
                }
            }
        }
    }
    return "No";
}
