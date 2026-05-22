class Solution {
  public:
    
    int n;
    
    vector<vector<int>>dp;
    
    bool fun(vector<int>& arr,int i,int sum) {
        
        if(i >= n) {
            if(sum == 0) return true;
            return false;
        }
        
        if(sum < 0) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool pick = fun(arr,i+1,sum-arr[i]);
        bool not_pick = fun(arr,i+1,sum);
        
        return dp[i][sum] = pick || not_pick;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n = arr.size();
        
        dp.resize(n,vector<int>(sum+1,-1));
        
        bool ans = fun(arr,0,sum);
        
        return ans;
        
        
    }
};