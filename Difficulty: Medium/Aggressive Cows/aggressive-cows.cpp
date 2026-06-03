class Solution {
  public:
    
    int fun(vector<int> &stalls, int mid) {
        
        int cnt = 1;
        
        int lastPos = stalls[0];
        
        for(int i = 1 ; i < stalls.size() ; i++) {
            
            if(stalls[i] - lastPos >= mid) {
                cnt++;
                lastPos = stalls[i];
            }
        }
        
        return cnt;
        
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        
        int n = stalls.size();
        
        sort(stalls.begin(),stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        int ans = 0;
        
        while(low <= high) {
            
            int mid = (low + high)/2;
            
            if(fun(stalls,mid) >= k) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
            
        }
        
        return ans;
    }
};