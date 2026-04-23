class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        
        int total = accumulate(arr.begin(),arr.end(),0);
        
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            if(sum == total) return true;
            
            sum += arr[i];
            total -= arr[i];
        }
        
        return false;
    }
};
