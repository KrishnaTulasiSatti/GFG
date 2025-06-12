class Solution {
  public:
  vector<int>dp;
  
  int fun(vector<int>&height,int i,int n) {
     if(i == n-1) return 0;
     
     if(i >= n) return INT_MAX;
     
     if(dp[i] != -1) return dp[i];
     
     int onestep = fun(height,i+1,n)+abs(height[i]-height[i+1]);
     
     int twostep = INT_MAX;
     
     if(i+2 < n) {
         twostep = fun(height,i+2,n)+abs(height[i]-height[i+2]);
     }
     
     return dp[i] = min(onestep,twostep);
     
  }
    int minCost(vector<int>& height) {
        // Code here
        dp.resize(height.size(),-1);
        
        return fun(height,0,height.size());
        
    }
};