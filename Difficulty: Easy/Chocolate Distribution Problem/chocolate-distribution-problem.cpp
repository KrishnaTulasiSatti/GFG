class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        
        sort(a.begin(),a.end());
        
        int mini = INT_MAX;
        
        int l = 0;
        int r = m;
        
        while(r < a.size()) {
            mini = min(mini,a[r-1]-a[l]);
            r++;
            l++;
        }
        
        mini = min(mini,a[r-1]-a[l]);
        
        return mini;
        
    }
};