class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxi = 0;
        
        int l = 0;
        int r = arr.size()-1;
        
        while(l < r) {
            maxi = max(maxi,min(arr[l],arr[r])*(r-l));
            
            if(arr[l] < arr[r]) l++;
            else r--;
        }
        
        return maxi;
        
    }
};