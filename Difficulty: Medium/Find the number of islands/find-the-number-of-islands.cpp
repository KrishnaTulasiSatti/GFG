class Solution {
  public:
    
    int m;
    int n;
    
    void fun(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis) {
        
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        
        if(grid[i][j] == 'W') return;
        
        if(vis[i][j] == 1) return;
        
        vis[i][j] = 1;
        
        fun(grid,i,j+1,vis);
        fun(grid,i,j-1,vis);
        fun(grid,i-1,j,vis);
        fun(grid,i+1,j,vis);
        
        fun(grid,i+1,j+1,vis);
        fun(grid,i+1,j-1,vis);
        fun(grid,i-1,j+1,vis);
        fun(grid,i-1,j-1,vis);
        

        
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int cnt = 0;
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 'L') {
                    fun(grid,i,j,vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
        
        
    }
};