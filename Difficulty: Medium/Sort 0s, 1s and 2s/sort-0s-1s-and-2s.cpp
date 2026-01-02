class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int ones = 0;
        int zeroes = 0;
        int twos = 0;
        
        for(auto it : arr) {
            if(it == 1) ones++;
            else if(it == 2) twos++;
            else zeroes++;
        }
        
        int i = 0;
        
        while(zeroes-- && i < arr.size()) arr[i++] = 0;
        while(ones-- && i < arr.size()) arr[i++] = 1;
        while(twos-- && i < arr.size()) arr[i++] = 2;
        
    }
};