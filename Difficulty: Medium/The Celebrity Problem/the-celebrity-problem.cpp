class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        
        vector<int>vec;
        
        for(int j = 0 ; j < mat[0].size() ; j++) {
            int sum = 0;
            for(int i = 0 ; i < mat.size() ; i++) {
                sum += mat[i][j];
            }
            if(sum == mat.size()) {
                vec.push_back(j);
            }
        }
        
        for(auto it : vec) {
            int f = 1;
            for(int i = 0 ; i < mat[0].size() ; i++) {
                if(it == i) continue;
                if(mat[it][i] == 1) f = 0;
            }
            if(f == 1) return it;
        }
        return -1;
         
    }
};