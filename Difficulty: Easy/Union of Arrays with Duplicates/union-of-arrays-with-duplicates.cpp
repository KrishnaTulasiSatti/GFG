class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int>s;
        
        for(auto it : a) s.insert(it);
        
        for(auto it : b) s.insert(it);
        
        vector<int>res(s.begin(),s.end());
        
        return res;
        
        
    }
};