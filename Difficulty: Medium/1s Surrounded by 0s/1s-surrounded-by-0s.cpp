class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if(grid[i][j] == 1) {
                        q.push({i,j});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            int r = top.first;
            int c = top.second;
            
            for(int i = 0 ; i < 4 ; i++) {
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(grid[nr][nc] == 1) {
                        q.push({nr,nc});
                        grid[nr][nc] = 0;
                    }
                }
            }
            
            
        }
        
        
        int cnt = 0;
        for(auto& it : grid) {
            for(auto& i : it) {
                if(i == 1) cnt++;
            }
        }
        
        return cnt;
    }
    
};