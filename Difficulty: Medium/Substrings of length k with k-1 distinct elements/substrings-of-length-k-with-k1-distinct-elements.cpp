class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        
        unordered_map<char,int>m;
        
        for(int i = 0 ; i < k ; i++) {
            m[s[i]]++;
        }
        
         int cnt = 0;
        
        if(m.size() == k-1) cnt++;
        
        int l = 0;
        int r = k;
        
      
        
        while(r < s.size()) {
            m[s[l]]--;
            m[s[r]]++;
            
            if(m[s[l]] == 0) m.erase(s[l]);
            
            if(m.size() == k-1) cnt++;
            
            l++;
            r++;
        }
        
        return cnt;
    }
};