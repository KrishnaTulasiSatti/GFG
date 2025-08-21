class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<int,int>m;
        
        int l = 0;
        int r = 0;
        
        int maxi = -1;
        
        while(r < s.size()) {
            m[s[r]]++;
            
            while(m.size() > k && l < s.size()) {
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            
            if(m.size() == k) maxi = max(maxi,r-l+1);
            r++;
        }
        
        return maxi;
    }
    
};