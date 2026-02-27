class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        
        int cnt = 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>pref(n,vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(j == 0) pref[i][j] = mat[i][j];
                else pref[i][j] = mat[i][j] + pref[i][j-1];
            }
        }
        
        vector<vector<int>>pref2(n,vector<int>(m,0));
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(j == 0) pref2[j][i] = pref[j][i];
                else pref2[j][i] = pref[j][i] + pref2[j-1][i];
            }
        }
        
        // for(auto it : pref2) {
        //     for(auto i : it) cout << i << " ";
        //     cout << endl;
        // }
        
        for(int s = 0 ; s < min(n,m) ; s++) {
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < m ; j++) {
                    
                    int r = i+s;
                    int c = j+s;
                    
                    if(r < n && c < m) {
                        
                        int sum = pref2[r][c];
                        
                        if(r < n && j-1 >= 0) sum -= pref2[r][j-1];
                        
                        if(i-1 >= 0 && c < m) sum -= pref2[i-1][c];
                        
                        if(i-1 >= 0 && j-1 >= 0) sum += pref2[i-1][j-1];
                        
                        if(sum == x) cnt++;
                    
                    }
                    
                }
            }
            
         }
        return cnt;
    }
};