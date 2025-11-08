class Solution {
  public:
    vector<vector<vector<int>>>dp;
    
    int fun(vector<vector<int>>& mat,int k,int i,int j,int m,int n,int sum) {
        
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        
        sum = sum + mat[i][j];
        
        if(sum > k) return 0;
        
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        
        if(i == m-1 && j == n-1) {
            if(sum == k) return 1;
            return 0;
        }
        
        int r = fun(mat,k,i,j+1,m,n,sum);
        
        int d = fun(mat,k,i+1,j,m,n,sum);
        
        return dp[i][j][sum] = r+d;
        
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        
        
        int m = mat.size();
        int n = mat[0].size();
        
        
        dp.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        
        
        return fun(mat,k,0,0,m,n,0);
    }
};