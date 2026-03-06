class Solution {
  public:
    
    bool check(vector<int>&frq1,vector<int>&frq2) {
        
        for(int i = 0 ; i < 26 ; i++) {
            if(frq2[i] < frq1[i]) return false;
        }
        
        return true;
    }
    string minWindow(string &s, string &p) {
        // code here
        
        vector<int>frq1(26,0);
        vector<int>frq2(26,0);
        
        for(int i = 0 ; i < p.size() ; i++) {
            frq1[p[i]-'a']++;
        }
        
        int l = 0;
        int r = 0;
        
        int mini = INT_MAX;
        
        string res = "";
        while(r < s.size()) {
            frq2[s[r]-'a']++;
            
            while(check(frq1,frq2)) {
                
                if((r-l+1) < mini) {
                    res = s.substr(l,(r-l+1));
                    mini = r-l+1;
                }
                frq2[s[l]-'a']--;
                l++;
                
            }
            
         
         //   cout << res << endl;
            
            r++;
            
        }
        
        return res;
    }
};