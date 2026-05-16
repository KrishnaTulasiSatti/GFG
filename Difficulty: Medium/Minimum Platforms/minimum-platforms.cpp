class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        
        vector<int>ans(2360,0);
        
        for(int i = 0 ; i < arr.size() ; i++) {
            ans[arr[i]] += 1;
            ans[dep[i]+1] += -1;
        }
        
        int mini = 0;
        
        int sum = 0;
        
        for(int i = 0 ; i < ans.size() ; i++) {
            sum += ans[i];
            mini = max(mini,sum);
        }
        
        return mini;
    }
};
