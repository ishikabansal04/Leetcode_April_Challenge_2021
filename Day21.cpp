class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int j=i; j>=0; j--){
                dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j];
            }
        }   
        return dp[0][0];
    }
};
