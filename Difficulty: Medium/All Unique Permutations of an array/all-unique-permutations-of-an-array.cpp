class Solution {
  public:
    
    vector<vector<int>>ans;
    
    void fun(vector<int>&arr,int n,vector<int>&vis,vector<int>&res) {
        
        if(res.size() == arr.size()) {
            ans.push_back(res);
            return;
        }
        
        
        for(int j = 0 ; j < n ; j++) {
            
            if (j > 0 && arr[j] == arr[j - 1] && vis[j-1]) continue; 
            if(!vis[j]) {
                vis[j] = 1;
                res.push_back(arr[j]);
                fun(arr,n,vis,res);
                res.pop_back();
                vis[j] = 0;
            }
        }
       
        
    }
    
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        
        vector<int>vis(n,0);
        
        vector<int>res;
        
        fun(arr,n,vis,res);
        
        return ans;
        
    }
};