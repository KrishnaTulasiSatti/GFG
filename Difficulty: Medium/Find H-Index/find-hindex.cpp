class Solution {
  public:
  
  int cnt(int x,vector<int>&citations) {
      int c = 0;
      for(auto it : citations) {
          if(it >= x) c++;
      }
      
      return c;
  }
    int hIndex(vector<int>& citations) {
        // code here
        
        int low = 0;
        int high = *max_element(citations.begin(),citations.end());
        
        int maxi = 0;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            int ans = cnt(mid,citations);
            
            if(ans >= mid) {
                maxi = max(maxi,mid);
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        
        return maxi;
        
    }
};