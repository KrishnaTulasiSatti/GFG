class Solution {
  public:
    
    
    void fun(vector<vector<char>>& grid,int i,int j) {
        
        queue<pair<int,int>>q;
        
        q.push({i,j});
        
        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};
        
        while(!q.empty()) {
            
            auto top = q.front();
            q.pop();
            
            int row = top.first;
            int col = top.second;
            
            grid[row][col] = 'T';
            
            for(int i = 0 ; i < 4 ; i++) {
                
                int r = row + dr[i];
                int c = col + dc[i];
                
                if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 'O') {
                    q.push({r,c});
                }
            }
        }
    }

    void fill(vector<vector<char>>& grid) {
        // Code here
        
       
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                
                if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) {
                    
                    if(grid[i][j] == 'O') {
                        fun(grid,i,j);
                    }
                }
            }
        }
        
        
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                if(grid[i][j] == 'T') grid[i][j] = 'O';
            }
        }
    
        
        
        
    }
};