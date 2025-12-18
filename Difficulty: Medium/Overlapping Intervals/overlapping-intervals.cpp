class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        
        int start = arr[0][0];
        int end = arr[0][1];
        
        vector<vector<int>>res;
        
        for(int i = 1 ; i < arr.size() ; i++) {
            
            int s = arr[i][0];
            int e = arr[i][1];
            
            if(s > end) {
                res.push_back({start,end});
                start = s;
                end = e;
            }
            else if(s >= start && e <= end) continue;
            else if(s >= start && e > end) end = e;
            
        }
        
        res.push_back({start,end});
        
        return res;
    }
};