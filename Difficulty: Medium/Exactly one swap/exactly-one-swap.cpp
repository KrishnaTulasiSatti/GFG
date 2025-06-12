class Solution {
  public:
    int countStrings(string &s) {
        // code here
        unordered_map<int,int>m;
        
        bool flag = false;
        
        for(auto it : s) {
            m[it]++;
            
            if(m[it] > 1) flag = true;
        }
        
        int res = 0;
        
        for(int i = s.size()-1 ; i >= 0 ; i--) {
            m[s[i]]--;
            
            if(i-m[s[i]] < 0) res += 0;
            else res += (i-m[s[i]]);
        }
        
        
        if(flag) res+=1;
        return res;
    }
};
