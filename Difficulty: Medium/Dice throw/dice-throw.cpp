class Solution {
  public:
    
    // int fun(int n,int m,int x) {
        
    //     if(n == 0 && x == 0) return 1;
        
    //     if(n == 0) return 0;
        
    //     int cnt = 0;
        
    //     for(int i = 1 ; i <= m ; i++) {
    //         cnt += fun(n-1,m,x-i);
    //     }
        
    //     return cnt;

    // }
    int noOfWays(int m, int n, int x) {
        // code here
        
        // int res = fun(n,m,x);
        // return res;
        
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));
        
        dp[0][0] = 1;
        
        for(int i = 1 ; i <= x ; i++) {
            for(int d = 1 ; d <= n ; d++) {
                for(int f = 1 ; f <= m ; f++) {
                    if(i >= f) dp[d][i] += dp[d-1][i-f];
                }
            }
        }
        
        return dp[n][x];
    }
};