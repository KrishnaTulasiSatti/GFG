class Solution {
  public:
  
  int fun(vector<int>&arr,int k,int mid) {
      int cnt = 0;
      
      int len = 0;
      
      for(int i = 0 ; i < arr.size() ; i++) {
          
          if(arr[i] <= mid) {
              len++;
          }
          else {
              len = 0;
          }
          
          if(len == k) {
              cnt++;
              len = 0;
          }
      }
      
      return cnt;
  }
  
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int low = *min_element(arr.begin(),arr.end());
        
        int high = *max_element(arr.begin(),arr.end());
        
        int mini = INT_MAX;
        
        while(low <= high) {
            
            int mid = (low + high)/2;
            
            int cnt = fun(arr,k,mid);
            
          //  cout << cnt << " " << mid << endl;
            
            if(cnt >= m) {
                high = mid-1;
                mini = min(mini,mid);
            }
            else low = mid+1;
            
            
        }
        
        return mini == INT_MAX ? -1 : mini;
    }
};