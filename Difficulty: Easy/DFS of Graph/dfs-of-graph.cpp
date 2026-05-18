class Solution {
  public:
    
    vector<int>ans;
    
    void dfs(vector<int>&vis,vector<vector<int>>&adj,int src){
        
        ans.push_back(src);
        vis[src] = 1;
        
        for(auto it : adj[src]) {
            if(vis[it] == -1) dfs(vis,adj,it);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        int n = adj.size();
        
        vector<int>vis(n,-1);
        
        for(int i = 0 ; i < n ; i++) {
            if(vis[i] == -1) dfs(vis,adj,i);
        }
        
        return ans;
        
    }
};