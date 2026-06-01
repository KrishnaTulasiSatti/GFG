class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        
        long long pro = 1;
        
        if(arr.size() == 1) return arr[0];
        
        sort(arr.begin(),arr.end());
        
        int n = 0;
        int p = 0;
        
        for(auto& it : arr) {
            if(it < 0) n++;
            else if(it > 0) p++;
        }
        
        if(n <= 1 && p == 0) return 0;
        
        int i = 0;
        
        if(n % 2) n--;
        
        
        const int mod = 1e9+7;
        
        while(n--) {
            pro = (mod + arr[i] * pro) % mod;
            i++;
        }
        
        for(auto& it : arr) {
            
            if(it > 0) {
                pro = (mod + it * pro) % mod;
            }
        }
        return (int)((pro + mod) % mod);
        
    }
};
