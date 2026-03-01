class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
    
        
        int i = 0;
        for(int j = 0 ; j < arr.size() ; j++) {
            if(arr[j] == 0) continue;
            arr[i++] = arr[j];
        }
        
        while(i < arr.size()) {
            arr[i++] = 0;
        }
    }
};