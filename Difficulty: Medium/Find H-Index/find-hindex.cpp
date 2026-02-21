class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        
        sort(citations.begin(),citations.end());
        
        int n = citations.size();
        
        for(int i = citations[n-1] ; i >= 0 ; i--) {
            
            int lb = n-(lower_bound(citations.begin(),citations.end(),i)-citations.begin());
            
            if(lb >= i) return i;
            
        }
        return 0;
    }
};