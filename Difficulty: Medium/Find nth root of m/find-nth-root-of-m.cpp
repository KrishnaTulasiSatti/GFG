class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        
        int low = 0;
        int high = m;
        
        int ans = 0;
        
        while(low <= high) {
            
            int mid = (low + high)/2;
            
            int num = 1;
            
            for(int i = 1 ; i <= n ; i++) num = num * mid;
            
            if(num == m) return mid;
            
            if(num < m) low = mid+1;
            else high = mid-1;
            
        }
        
        return -1;
    }
};