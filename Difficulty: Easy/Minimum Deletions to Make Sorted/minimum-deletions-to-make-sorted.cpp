class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        vector<int>temp;
        temp.push_back(arr[0]);
        
        for(int i = 1 ; i < n ; i++) {
            int idx =  lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            
            if(idx == temp.size()) temp.push_back(arr[i]);
            else temp[idx] = arr[i];
        }
        
        return n - temp.size();
    }
};