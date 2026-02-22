class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>m;
        m[0]++;
        
        int xr = 0;
        
        int cnt = 0;
        
        for(auto it : arr) {
            xr ^= it;
            if(m.find(xr^k) != m.end()) {
                cnt+=m[xr^k];
            }
            m[xr]++;
        }
        
        return cnt;
    }
};