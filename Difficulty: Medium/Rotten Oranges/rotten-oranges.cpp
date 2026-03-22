class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int cnt = 0;
        
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[0].size() ; j++) {
                if(mat[i][j] == 2) q.push({i,j});
            }
        }
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        
        while(!q.empty()) {
            
            int size = q.size();
            bool flag = false;
            for(int i = 0 ; i < size ; i++) {
                auto top = q.front();
                q.pop();
                int r = top.first;
                int c = top.second;
                for(int j = 0 ; j < 4 ; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                        q.push({nr,nc});
                        mat[nr][nc] = 2;
                        flag = true;
                    }  
                }
            }
            
            if(flag) cnt++;
            
            
        }
        
        for(auto it : mat) {
            for(auto i : it) {
                if(i == 1) return -1;
            }
        }
        
        return cnt;
    }
};