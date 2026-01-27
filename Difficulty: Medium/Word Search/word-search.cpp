class Solution {
  public:
    int m,n;
    
    bool fun(int i,int j,vector<vector<char>> &mat, string &word,int k,vector<vector<int>>&vis) {
        
        if(k == word.size()) return true;
        
        if(i < 0 || i >=m || j < 0 || j >= n) return false;
        
        if(mat[i][j] != word[k]) return false;
        
        if(vis[i][j] == 1) return false;
        
        vis[i][j] = 1;
        
        bool left = fun(i,j+1,mat,word,k+1,vis);
        bool right = fun(i,j-1,mat,word,k+1,vis);
        bool top = fun(i-1,j,mat,word,k+1,vis);
        bool bottom = fun(i+1,j,mat,word,k+1,vis);
        
        vis[i][j] = 0;
        
        return left || right || top || bottom;
        
        
        
        
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        m = mat.size();
        n = mat[0].size();
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                vector<vector<int>>vis(m,vector<int>(n,-1));
                if(fun(i,j,mat,word,0,vis)) return true;
            }
        }
        
        return false;
    }
};