/*
    单调性：副对角线O(m+n)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();//m x n
        int i = 0,j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};