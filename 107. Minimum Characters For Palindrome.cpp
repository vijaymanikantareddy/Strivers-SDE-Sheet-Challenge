
int minCharsforPalindrome(string str) {
	// Write your code here.
	int res = 0, i = 0, j = str.size()-1, temp = str.size()-1;
	while(i < j){
		if(str[i] != str[j]){
			i = 0;
			j = --temp;
			res++;
		}else{
			i++;
			j--;
		}
	}
	return res;
}
