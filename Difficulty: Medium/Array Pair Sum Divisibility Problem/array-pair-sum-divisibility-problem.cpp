class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        
        
        // Code here.
        
        
        
        unordered_map<int,int>m;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            
            int rem = arr[i] % k;
            
            m[rem]++;
            
            
        }
        
        for(auto it : m) {
            
            if(it.first == 0) {
                
                if(it.second % 2) return false;
        
            }
            
            else {
                int a = it.first;
                int b = k - a;
                
                if(m[a] != m[b]) return false;
            }
        }
       
        
        return true;
    }
};