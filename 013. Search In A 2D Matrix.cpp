bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int small = mat[0][0], large = mat[n-1][m-1];
    int i = 0, j = m-1;
    if(target < small || target > large){
        return false;
    }
    while(i < n && j >= 0){
        if(mat[i][j] == target){
            return true;
        }
        if(mat[i][j] < target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}
