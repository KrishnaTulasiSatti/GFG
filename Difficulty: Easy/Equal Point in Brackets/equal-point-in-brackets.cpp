class Solution {
  public:
    int findIndex(string &s) {
        // code here
        
        int op = 0;
        int cl = 0;
        
        for(auto& it : s) {
            if(it == ')') cl++;
        }
        
        if(cl == 0) return 0;
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '(') op++;
            else cl--;
            
            if(op == cl) return i+1;
        }
        
        return s.size();
    }
};