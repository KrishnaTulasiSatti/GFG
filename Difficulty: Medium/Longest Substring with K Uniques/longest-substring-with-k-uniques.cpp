class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int ans = -1;
        
        int l = 0;
        int r = 0;
        
        unordered_map<char,int>m;
        
        while(r < s.size()) {
            m[s[r]]++;
            
            while(m.size() > k) {
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            
            if(m.size() == k) ans = max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};