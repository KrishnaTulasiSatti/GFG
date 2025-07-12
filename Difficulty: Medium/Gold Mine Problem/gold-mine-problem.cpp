class Solution {
  public:
  
   int fun(vector<vector<int>>&mat,int i,int j,int m,int n,vector<vector<int>>&dp) {
       
       if(i < 0 || i >= m || j < 0 || j >= n) return 0;
       
       if(j == n-1) return mat[i][j];
       
       if(dp[i][j] != -1) return dp[i][j];
       
       
       int dur = mat[i][j] + fun(mat,i-1,j+1,m,n,dp);
       int r = mat[i][j] + fun(mat,i,j+1,m,n,dp);
       int ddr = mat[i][j] + fun(mat,i+1,j+1,m,n,dp);
       
       return dp[i][j] = max({ddr,r,dur});
       
       
   }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int res = INT_MIN;
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i = 0 ; i < m ; i++) {
            res = max(res,fun(mat,i,0,m,n,dp));
        }
        
        return res;
    }
};