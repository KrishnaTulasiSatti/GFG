class Solution {
  public:
  
  int count(vector<int>&arr,int x) {
      int cnt= 0;
      
      for(int i = 0 ; i < arr.size() ; i++) {
          cnt += (arr[i]/x);
          if(arr[i] % x) cnt++;
      }
      
      return cnt;
  }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        
        int high = *max_element(arr.begin(),arr.end());
        
        int ans = 0;
        
        while(low <= high) {
            
            int mid = (low+high)/2;
            
            int cnt = count(arr,mid);
            
            if(cnt <= k) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
            
        }
        
        return ans;
    }
};