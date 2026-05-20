// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto& it : edges) {
            
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        
        pq.push({0,0});
        
        vector<int>dist(V,1e9);
        dist[0] = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            int d = top.first;
            
            for(auto& it : adj[node]) {
                
                if(d + it.second < dist[it.first]) {
                    pq.push({d+it.second,it.first});
                    dist[it.first] = d+it.second;
                }
            }
        }
        
        for(auto& it : dist) {
            if(it == 1e9) it = -1;
        }
        return dist;
    }
};
