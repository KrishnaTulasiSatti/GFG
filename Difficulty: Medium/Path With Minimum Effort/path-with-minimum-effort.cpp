class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        
        pq.push({0,0,0});
        dist[0][0] = 0;
        
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int max_cost = top[0];
            int r = top[1];
            int c = top[2];
            
            for(int i = 0 ; i < 4 ; i++) {
                
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    
                    int new_cost = max(max_cost,abs(mat[r][c]-mat[nr][nc]));
                    
                    if(dist[nr][nc] > new_cost) {
                        dist[nr][nc] = new_cost;
                        pq.push({new_cost,nr,nc});
                    }
                }
            }
            
        }
        
        return dist[n-1][m-1];
    }
};
