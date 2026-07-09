class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        
        for(int i = 0 ; i < arr.size() ; i++) {
            arr[i] = arr[i] % k;
        }
        
        unordered_map<int,int>mp;
        
        int cnt = 0;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            
            int need = abs(k-arr[i]);
            if(need == k) cnt += mp[0];
            
            if(mp.find(need) != mp.end()) {
                cnt += mp[need];
            }
            mp[arr[i]]++;
        }
        
        return cnt;
    }
}; 