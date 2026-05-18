class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        
        vector<int>vis(V,-1);
        
        vector<vector<int>>adj(V);
        
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        
        for(int i = 0 ; i < V ; i++) {
            if(vis[i] == -1) {
                queue<pair<int,int>>q;
                
                q.push({i,-1});
                vis[i] = 1;
                
                while(!q.empty()) {
                    auto top = q.front();
                    q.pop();
                    int node = top.first;
                    int p = top.second;
                    
                    
                    for(auto it : adj[node]) {
                        if(vis[it] == -1) {
                            vis[it] = 1;
                            q.push({it,node});
                        }
                        else if(it != p) return true;
                    }
                }
            }
        }
        
        return false;
        
        
    }
};