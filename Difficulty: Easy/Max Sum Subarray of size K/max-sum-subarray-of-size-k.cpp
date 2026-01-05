class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        
        int maxi = 0;
        
        for(int i = 0 ; i < k ; i++) {
            sum += arr[i];
        }
        
        maxi = sum;
        
        int l = 0;
        int r = k;
        
        while(r < arr.size()) {
            sum -= arr[l++];
            sum += arr[r++];
            
            maxi = max(maxi,sum);
        }
        
        return maxi;
    }
};