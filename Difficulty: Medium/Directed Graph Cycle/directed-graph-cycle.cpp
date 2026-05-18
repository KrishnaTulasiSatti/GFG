class Solution {
  public:
    
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis,int src) {
        vis[src] = 1;
        pathVis[src] = 1;
        
        for(auto it : adj[src]) {
            if(vis[it] == -1) {
                if(dfs(adj,vis,pathVis,it)) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        
        pathVis[src] = -1;
        
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>adj(V);
        
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V,-1);
        vector<int>pathVis(V,-1);
        
        for(int i = 0 ; i < V ; i++) {
            
            if(vis[i] == -1) {
                if(dfs(adj,vis,pathVis,i)) return true;
            }
            
        }
        
        return false;
    }
};