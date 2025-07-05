class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
         unordered_map<int,int>m;
        
        int cnt = 0;
        
        int l = 0;
        int r = 0;
        
        while(r < arr.size()) {
            m[arr[r]]++;
            
            while(m.size() > k) {
                m[arr[l]]--;
                if(m[arr[l]] == 0) m.erase(arr[l]);
                l++;
            }
            
            if(m.size() <= k) {
                cnt+=(r-l+1);
            }
            
            
            r++;
        }
        
        return cnt;
    }
};