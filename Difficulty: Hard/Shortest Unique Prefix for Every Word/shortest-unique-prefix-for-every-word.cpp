class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        
        unordered_map<string,int>mp;
        
        for(auto& it : arr) {
            string str = "";
            for(auto& ch : it) {
                str += ch;
                mp[str]++;
            }
        }
        
        vector<string>res;
        
        for(auto& it : arr) {
            string ans = "";
            int f = 0;
            for(auto& ch : it) {
                ans += ch;
                if(mp[ans] == 1) {
                    f = 1;
                    res.push_back(ans);
                    break;
                }
            }
            
            if(f == 0) res.push_back(it);
        }
        
        return res;
        
    }
};