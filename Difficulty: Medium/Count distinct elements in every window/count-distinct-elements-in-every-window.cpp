class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        
        int cnt = 0;
        
        vector<int>res;
        
        unordered_map<int,int>m;
        
        for(int i = 0 ; i < k ; i++) {
            m[arr[i]]++;
        }
        
        res.push_back(m.size());
        
        int l = 0;
        int r = k;
        
        while(r < arr.size()) {
            m[arr[l]]--;
            if(m[arr[l]] == 0) m.erase(arr[l]);
            m[arr[r]]++;
            
            l++;
            r++;
            
            res.push_back(m.size());
        }
        
        return res;
        
    }
};