class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int maxi = 0;
        
        unordered_map<int,int>m;
        
        int l = 0;
        int r = 0;
        
        while(r < arr.size()) {
            m[arr[r]]++;
            
            while(m.size() > 2) {
                m[arr[l]]--;
                if(m[arr[l]] == 0) m.erase(arr[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        
        return maxi;
    }
};