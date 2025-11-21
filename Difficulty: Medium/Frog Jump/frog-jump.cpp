class Solution {
  public:
  
  vector<int>dp;
  
  int fun(vector<int>&height,int i,int n) {
      
      if(i == n-1) return 0;
      
      if(i >= n) return INT_MAX;
      
      if(dp[i] != -1) return dp[i];
      
      int step1 = INT_MAX;
      int step2 = INT_MAX;
      
      if(i+1 < n) {
          step1 = abs(height[i]-height[i+1])+fun(height,i+1,n);
      }
      
      if(i+2 < n) {
          step2 = abs(height[i]-height[i+2])+fun(height,i+2,n);
      }
      
   //   cout << step1 << " " << step2 << endl;
      
      return dp[i] = min(step1,step2);
      
  }
    int minCost(vector<int>& height) {
        // Code here
        
        int n = height.size();
        
        dp.resize(n,-1);
        
        int ans = fun(height,0,n);
        
        return ans;
    }
};