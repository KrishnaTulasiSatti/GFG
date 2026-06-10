class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        // code here
        
        int cnt = 0;
        
        int n = arr.size();
        
        for(auto& it : arr) {
            
            int low = 0;
            int high = n-1;
            
            while(low <= high) {
                int mid = (low + high)/2;
                
                if(arr[mid] == it) {
                    cnt++;
                    break;
                }
                else if(arr[mid] < it) low = mid+1;
                else high = mid-1;
        
            }
            
            
        }
        return cnt;
        
    }
};