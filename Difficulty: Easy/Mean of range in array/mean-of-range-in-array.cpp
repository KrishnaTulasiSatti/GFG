class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int>pref;
        pref.push_back(arr[0]);
        
        for(int i = 1 ; i < arr.size() ; i++) {
            pref.push_back(pref.back() + arr[i]);
        }
        
        vector<int>ans;
        
        for(auto it : queries) {
            int x = it[0];
            int y = it[1];
            
            int sum = (x == 0 ? pref[y] : pref[y]-pref[x-1]);
            ans.push_back(sum/(y-x+1));
        }
        
        return ans;
    }
};