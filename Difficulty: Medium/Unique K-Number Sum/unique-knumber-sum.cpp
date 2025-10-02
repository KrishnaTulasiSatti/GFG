class Solution {
  public:
    vector<vector<int>>ans;
    
    void fun(vector<int>&arr,int n,int k,vector<int>&vec,int i,int sum) {
        
        
        if(vec.size() == k) {
            
            if(sum == n) ans.push_back(vec);
            return;
        }
        
        if(i >= arr.size()) return;
        
        vec.push_back(arr[i]);
        
        fun(arr,n,k,vec,i+1,sum+arr[i]);
        
        vec.pop_back();
        
        fun(arr,n,k,vec,i+1,sum);
        
        
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        
        vector<int>arr = {1,2,3,4,5,6,7,8,9};
        
        vector<int>vec;
        
        fun(arr,n,k,vec,0,0);
        
        return ans;
        
    }
};