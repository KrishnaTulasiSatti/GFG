class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        
        int n = adj.size();
        
        vector<int>vis(n,-1);
        
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        
        vector<int>ans;
        // ans.push_back(0);
        
        while(!q.empty()) {
            
            auto top = q.front();
            q.pop();
            
            ans.push_back(top);
            
            for(auto it : adj[top]) {
                if(vis[it] == -1) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return ans;
    }
};