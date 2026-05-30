class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        int last2 = arr[n-2];
        
        arr[0] = arr[0] ^ arr[1];
        int pref = arr[0];
        
        for(int i = 1 ; i < arr.size()-1 ; i++) {
            arr[i] = pref ^ arr[i+1] ^ arr[i];
            pref ^= arr[i];
        }
        
        arr[n-1] ^= last2;
    }
};