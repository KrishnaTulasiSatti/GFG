class Solution {
  public:
    
    int n;
    
    vector<vector<int>>dp;
    
    int fun(string&s ,int i, int ps) {
        
        if(i >= n) return 1;
        
        if(dp[i][ps] != -1) return dp[i][ps];
        
        int sum = 0;
        int ways = 0;
        
        for(int j = i ; j < n ; j++) {
            
            sum += (s[j]-'0');
            
            if(sum >= ps) {
                ways += fun(s,j+1,sum);
            }
            
        }
        
        return dp[i][ps] = ways;
        
        
        
    }
    
    
    int validGroups(string &s) {
        // code here
        
        n = s.size();
        dp.resize(n,vector<int>(1000,-1));
        
        int cnt = fun(s,0,0);
        
        return cnt;
        
        
        
    }
};