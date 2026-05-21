class Solution {
  public:
    
    int n;
    
    vector<int>dp;
    
    int fun(vector<int>& height,int i) {
        
        if(i == n-1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        // One step 
        
        int one = INT_MAX;
        int two = INT_MAX;
        
        if(i+1 < n) one = abs(height[i]-height[i+1]) + fun(height,i+1);
        
        if(i+2 < n) two = abs(height[i]-height[i+2]) + fun(height,i+2);
        
        return dp[i] = min(one,two);
        
    }
    
    int minCost(vector<int>& height) {
        // Code here
        n = height.size();
        dp.resize(n,-1);
        
        int ans = fun(height,0);
        
        return ans;
        
    }
};