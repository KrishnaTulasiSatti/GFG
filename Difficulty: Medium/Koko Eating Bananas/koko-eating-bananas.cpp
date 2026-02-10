class Solution {
  public:
    int fun(vector<int>&arr,int mid) {
        int cnt = 0;
        
        for(auto it : arr) {
            cnt += it/mid;
            if(it % mid) cnt++;
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
             
             int cnt = fun(arr,mid);
             
             if(cnt <= k) {
                 ans = mid;
                 high = mid-1;
             }
             else low = mid+1;
         }
         
         return ans;
    }
};