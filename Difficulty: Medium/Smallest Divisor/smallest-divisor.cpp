class Solution {
  public:
  
 int fun(int x,vector<int>&arr) {
     int cnt = 0;
     
     for(int i = 0 ; i < arr.size() ; i++) {
         
         
         cnt += (arr[i]/x);
         if(arr[i] % x) cnt++;
     }
     
     return cnt;
 }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *max_element(arr.begin(),arr.end());
        
        int ans = -1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            
            int cnt = fun(mid,arr);
            
            if(cnt <= k) {
                high = mid-1;
                ans = mid;
            } 
            else {
                low = mid+1;
            }
        }
        
        
        return ans;
    }
};
