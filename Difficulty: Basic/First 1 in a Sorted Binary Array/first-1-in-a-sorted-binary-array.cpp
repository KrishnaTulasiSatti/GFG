class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        // Your code goes here
        
        int i = -1;
        int j = arr.size();
        
        while((j-i) > 1) {
            int mid = (i+j)/2;
            if(arr[mid] < 1) {
                i = mid;
            }
            else {
                j = mid;
            }
        }
        
        if(j >= arr.size()) return -1;
        return j;
    }
};