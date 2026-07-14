class Solution {
  public:
    
    bool isValid(int x,vector<int>&arr) {
        
        
        for(int i = 0 ; i < arr.size() ; i++) {
            if(x > arr[i]) {
                x += abs(x-arr[i]);
            }
            else {
                x -= abs(x-arr[i]);
            }
            
            if(x < 0) return false;
            if(x > 1e5 + 5) return true;
            
        }
        
        return true;
        
        
    }
    int find(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
    
        int low = 1;
        int high = 1e5 + 5;
        
       
        int ans = high;
        
        while(low <= high) {
            
            int mid = low + (high-low)/2;
            
            if(isValid(mid,arr)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};