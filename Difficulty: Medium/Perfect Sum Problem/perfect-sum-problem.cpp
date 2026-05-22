class Solution {
  public:
    
    int n;
    
    vector<vector<int>>dp;
    
    int fun(vector<int>&arr,int i,int target) {
        
        if(i == n) {
            if(target == 0) return 1;
            return 0;
        } 
        
        if(target < 0) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int pick = fun(arr,i+1,target-arr[i]);
        int not_pick = fun(arr,i+1,target);
        
        return dp[i][target] = pick + not_pick;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        n = arr.size();
        
        dp.resize(n,vector<int>(target+1,-1));
        
        int cnt = fun(arr,0,target);
        
        return cnt;
        
    }
};