class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        
      
        
        int maxEnd = 0;
        
        for(auto it : arr) {
            maxEnd = max({maxEnd,it[1],it[0]});
        }
        
        vector<int>pref(maxEnd+1,0);
        
        
        for(int i = 0 ; i < arr.size() ; i++) {
            pref[arr[i][0]] += 1;
            if(arr[i][1] < maxEnd) pref[arr[i][1]+1] -=1;
        }
        
        int maxi = 0;
        
        int sum = 0;
        for(auto it : pref) {
            sum += it;
            maxi = max(maxi,sum);
            
        }
        
        return maxi;
        
    }
};
