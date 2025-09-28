class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        
        
        int l = 0;
        int r = 0;
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        int max_len = 0;
        
        int si = 0 , ei = 0;
        
        while(r < arr.size()) {
            
           maxi = *max_element(arr.begin()+l,arr.begin()+r+1);
           
           mini = *min_element(arr.begin()+l,arr.begin()+r+1);
           
           int diff = abs(maxi-mini);
           
        //   cout << maxi << " " << mini << " " << diff << endl;
           
           while(diff > x && l < arr.size()) {
               
               l++;
               
               maxi = *max_element(arr.begin()+l,arr.begin()+r);
           
               mini = *min_element(arr.begin()+l,arr.begin()+r);
               
               diff = abs(maxi-mini);
               
             //  cout << maxi << " " << mini << " " << diff << endl;
           }
           
           if(r-l+1 > max_len) {
               max_len = r-l+1;
               si = l;
               ei = r;
           }
           
           r++;
           
           
        }
        
        vector<int>ans;
        
        for(int i = si ; i <= ei ; i++) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};