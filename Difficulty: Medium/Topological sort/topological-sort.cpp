class Solution {
  public:
  
    void fun(vector<vector<int>>&adj,int src,vector<int>&vis,vector<int>&vec) {
        
        vis[src] = 1;
        
       
        
        for(auto it : adj[src]) {
            if(!vis[it]) {
                fun(adj,it,vis,vec);
            }
        }

         vec.push_back(src);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>>adj(V);
        
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V,0);
        
        vector<int>vec;
        
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i]) {
                fun(adj,i,vis,vec);
            }
        }
        
        reverse(vec.begin(),vec.end());
        
        return vec;
        
    }
};