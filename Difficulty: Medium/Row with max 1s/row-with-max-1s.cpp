// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int ans = -1;
        int maxi = 0;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            
            int lb = lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
            int ub = upper_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
            
            if(ub-lb > maxi) {
                maxi = ub-lb;
                ans = i;
            }
        }
        
        return ans;
    }
};