class Solution {
  public:
    
    vector<vector<int>>dp;
    
    int fun(vector<int>&a,vector<int>&b,int n,int m,int i,int j) {
        
        if(j == m) return 0;
        
        if(i == n) return -1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int pick = (a[i] * b[j]) + fun(a,b,n,m,i+1,j+1);
        int not_pick = fun(a,b,n,m,i+1,j);
        
        return dp[i][j] = max(pick,not_pick);
        
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        
        int n = a.size();
        int m = b.size();
        
        dp.resize(n,vector<int>(m,-1));
        int res = fun(a,b,n,m,0,0);
        
        return res;
    }
};
