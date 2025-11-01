class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        int n = edges.size();
        
        vector<vector<int>>adj(V);
        
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(V,-2);
        
        for(int i = 0 ; i < V ; i++) {
            
            if(vis[i] == -2) {
                
                // cout << i << "--->";
                
                queue<pair<int,int>>q;
        
                q.push({i,-1});
                vis[i] = -1;
                
                while(!q.empty()) {
                    
                    auto top = q.front();
                    q.pop();
                    
                    for(auto it : adj[top.first]) {
                        
        
                        if((vis[it] == -2)) {
                            vis[it] = top.first;
                            q.push({it,top.first});
                        }
                        else if(vis[it] > -2 && vis[top.first] != it) return true;
                    }
                }
                
            }
        }
        
        return false;
    }
};