class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        
        unordered_map<int,int>mp;
        
        for(auto& it : words) {
            for(auto& i : it) {
                mp[i-'a']++;
            }
        }
        vector<vector<int>>adj(26);
        
        vector<int>in(26);
        
        for(int i = 0 ; i < words.size()-1 ; i++) {
            
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(),s2.size());
            if (s1.length() > s2.length() && s1.substr(0, len) == s2) return "";
            for(int j = 0 ; j < len ; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    in[s2[j]-'a']++;
                    break;
                }
            }
        }
        
        string ans = "";
        
        queue<int>q;
        
        for(int i = 0 ; i < 26 ; i++) {
            if(mp.find(i) != mp.end()) {
                if(in[i] == 0) q.push(i);
            }
        }
        
        while(!q.empty()) {
            
            auto top = q.front();
            q.pop();
            if(mp.find(top) != mp.end()) ans += (top + 'a');
            
            for(auto& it : adj[top]) {
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }
        
        // cout << ans << endl;
         
        if(ans.size() != mp.size()) return "";
        
        return ans;
        
    }
};