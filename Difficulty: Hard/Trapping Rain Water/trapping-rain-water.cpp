class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>rMax(n,0);
        rMax[n-1] = arr[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--) rMax[i] = max(rMax[i+1],arr[i]);
        
        int lMax = arr[0];
        
        int maxi = 0;
        
        for(int i = 1 ; i < n-1 ; i++) {
            maxi += max(0,min(lMax,rMax[i+1])-arr[i]);
            lMax = max(lMax,arr[i]);
        }
        
        return maxi;
    }
};