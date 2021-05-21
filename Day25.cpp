class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int gap=1; gap<n ; gap++){
            for(int i=0, j= gap; j<n; i++, j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int left = 0, right = n-1; left<n/2; left++, right--){
            for(int i=0; i<n; i++){
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
            }
        }
    }
};
