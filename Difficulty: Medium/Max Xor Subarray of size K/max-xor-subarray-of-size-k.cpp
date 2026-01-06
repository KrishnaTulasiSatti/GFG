class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int maxi = 0;
        
        int xr = 0;
        
        for(int i = 0 ; i < k; i++) {
            xr ^= arr[i];
        }
        
        maxi = xr;
        
        int l = 0;
        int r = k;
        
        while(r < arr.size()) {
           // cout << xr << endl;
            xr ^= arr[r++];
            xr ^= arr[l++];
            maxi = max(maxi,xr);
        }
        
        return maxi;
    }
};