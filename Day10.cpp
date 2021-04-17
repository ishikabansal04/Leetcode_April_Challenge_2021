class Solution {
public:
    
    int longest(int sr, int sc, int er, int ec, vector<vector<int>>& matrix, vector<vector<bool>>&vis, vector<vector<int>>& dir, int previous, vector<vector<int>>&dp){
        if(sr>=er || sc>=ec || sr<0 || sc<0 || vis[sr][sc] || previous>= matrix[sr][sc]) return 0; 
        cout<< sr <<"   "<<sc<<endl;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        vis[sr][sc] = true;
        int templong=0;
        for(int i=0; i<dir.size(); i++){
            int newx = sr+dir[i][0];
            int newy = sc+dir[i][1];
            if(newx>=0 && newy>=0 && newx<er && newy<ec && matrix[newx][newy]>matrix[sr][sc] && dp[newx][newy]!=-1){    
                templong = max(templong, dp[newx][newy]);
            }
            else{
                templong = max(templong, longest(newx, newy, er, ec, matrix, vis, dir, matrix[sr][sc], dp));
            }
        }
        dp[sr][sc] = templong+1;
        vis[sr][sc] = false;
        return templong+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        vector<vector<int>>dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int m= matrix.size();
        int n= matrix[0].size();
        int maximum=INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]!=-1){
                    maximum = max(maximum, dp[i][j]);
                    continue;
                }
                vector<vector<bool>>vis(matrix.size(), vector<bool>(matrix[0].size(), false));
                maximum = max(maximum, longest(i, j, m, n, matrix, vis, dir, -1, dp));
            }
        }
        return maximum;
    }
};
