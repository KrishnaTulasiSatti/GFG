class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if(n == 1) return arr[0];
        if(n == 2) return 0;
        
        int res_xor = 0;
        
        int cnt = n;
        
        for(int i = 0 ; i < n ; i++) {
            
            if((i+1)*cnt % 2) res_xor ^= arr[i];
            cnt--;
        }
        
        return res_xor;
    }
};