class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        
        vector<int>frq(26,-1);
        
        int ans = 0;
        
        for(int i = 0 ; i < s.size() ; i++) {
            
            if(frq[s[i]-'a'] == -1) frq[s[i]-'a'] = i;
            else ans = max(ans,i-frq[s[i]-'a']);
        }
        
        return ans-1;
        
    }
};