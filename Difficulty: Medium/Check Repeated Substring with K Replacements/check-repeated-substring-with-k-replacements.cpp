class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        
        unordered_map<string,int>m;
        
        string str = "";
        
        for(int i = 0 ; i < s.size() ; i++) {
            str += s[i];
            if((i+1) % k == 0) {
                m[str]++;
                str = "";
            }
        }
        
        if(str != "") m[str]++;
        
        string maxi = "";
        
        int sc = 0;
        
        for(auto& it : m) {
            if(it.second > sc) {
                maxi = it.first;
                sc = it.second;
            }
        }
        
        int cnt = 0;
        
        for(auto& it : m) {
            if(it.first != maxi) cnt += it.second;
        }
        
        return cnt <= 1;
        
        
    }
};