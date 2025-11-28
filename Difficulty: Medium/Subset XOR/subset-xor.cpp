class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int>ans;
        
        int mod = n % 4;
        
        for(int i = 1 ; i <= n ; i++) {
            if(mod == 1 && i == n-1) continue;
            else if(mod == 2 && i == 1) continue;
            else if(mod == 3 && i == n) continue;
            
            ans.push_back(i);
        }
        
        return ans;
    }
};
