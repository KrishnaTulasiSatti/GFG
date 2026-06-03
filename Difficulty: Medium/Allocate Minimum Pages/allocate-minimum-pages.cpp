class Solution {
  public:
    
    int fun(vector<int>& arr,int mid) {
        
        int cnt = 1;
        
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            sum += arr[i];
            
            if(sum > mid) {
                cnt++;
                sum = arr[i];
            }
        }
        
        return cnt;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
    
        if(k > n) return -1;
        
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        int ans = 0;
        
        while(low <= high) {
            
            int mid = (low + high)/2;
            
            if(fun(arr,mid) <= k) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return ans;
        
    }
};