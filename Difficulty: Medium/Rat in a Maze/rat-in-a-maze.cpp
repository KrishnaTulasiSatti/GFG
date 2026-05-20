class Solution {
  public:
    
    vector<string>ans;
    
    int m,n;
    
    void fun(vector<vector<int>>&maze,int i,int j,vector<vector<int>>&vis,
    string& str) {
        
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        
        if(i == m-1 && j == n-1) {
            if(maze[i][j] == 1) ans.push_back(str);
            return;
        }
        
        if(vis[i][j] == 1 || maze[i][j] == 0) return;
        
        vis[i][j] = 1;
        
        // Left
        str += 'L';
        fun(maze,i,j-1,vis,str);
        str.pop_back();
        
        // Right
        str += 'R';
        fun(maze,i,j+1,vis,str);
        str.pop_back();
        
        // Top
        str += 'U';
        fun(maze,i-1,j,vis,str);
        str.pop_back();
        
        // Bottom
        str += 'D';
        fun(maze,i+1,j,vis,str);
        str.pop_back();
        
        vis[i][j] = 0;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        m = maze.size();
        n = maze[0].size();
        
        string str = "";
        
        vector<vector<int>>vis(m,vector<int>(n,-1));
        
        fun(maze,0,0,vis,str);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};