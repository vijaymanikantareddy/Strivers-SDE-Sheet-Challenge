#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int a[26] = {0}, b[26] ={0};
    for(int i = 0 ;i < str1.size() ; i++){
        int d = str1[i]-'a';
        a[d]++;
    }
    for(int i = 0 ;i < str2.size() ; i++){
        int d = str2[i]-'a';
        b[d]++;
    }
    for(int i = 0 ; i < 26 ; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
