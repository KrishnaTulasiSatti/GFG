class Solution {
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>pac(m,vector<int>(n,0));
        
        queue<pair<int,int>>p;
        
        for(int i = 0 ; i < n ; i++) {
            p.push({0,i});
            pac[0][i] = 1;
        }
        
        for(int i = 0 ; i < m ; i++) {
            p.push({i,0});
            pac[i][0] = 1;
        }
        
        vector<int>dr = {0,0,-1,1};
        vector<int>dc = {-1,1,0,0};
        
        while(!p.empty()) {
            
            auto top = p.front();
            p.pop();
            
            int r = top.first;
            int c = top.second;
            
            for(int i = 0 ; i < 4 ; i++) {
                
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && pac[nr][nc] != 1 && mat[nr][nc] >= mat[r][c]) {
                    p.push({nr,nc});
                    pac[nr][nc] = 1;
                }
            }
        }
        
        vector<vector<int>>at(m,vector<int>(n,0));
        
        queue<pair<int,int>>a;
        
        for(int i = 0 ; i < n ; i++) {
            a.push({m-1,i});
            at[m-1][i] = 1;
        }
        
        for(int i = 0 ; i < m ; i++) {
            a.push({i,n-1});
            at[i][n-1] = 1;
        }
        
        while(!a.empty()) {
            
            auto top = a.front();
            a.pop();
            
            int r = top.first;
            int c = top.second;
            
            for(int i = 0 ; i < 4 ; i++) {
                
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && at[nr][nc] != 1 && mat[nr][nc] >= mat[r][c]) {
                    a.push({nr,nc});
                    at[nr][nc] = 1;
                }

            }
        }
        
        int cnt = 0;
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(pac[i][j] == 1 && at[i][j] == 1) cnt++;
            }
        }
        
        return cnt;
        
        
        
        
        
    }
};