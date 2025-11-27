class Solution {
  public:
    
    vector<vector<int>>dp;
    
    bool fun(vector<int>&arr,int i,int n,int sum,int tar) {
        
        
        if(i >= n) {
            if(sum == tar) return true;
            return false;
        }
        
        if(sum > tar) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        
        bool pick = fun(arr,i+1,n,sum+arr[i],tar);
        bool not_pick = fun(arr,i+1,n,sum,tar);
        
        return dp[i][sum] = pick || not_pick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        dp.resize(n,vector<int>(sum+1,-1));
        bool res = fun(arr,0,n,0,sum);

        return res;
        
    }
};