class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        
        int sum = 0;
        
        sort(arr.begin(),arr.end(),greater<int>());
        
        int i = 0;
        
        while(i < arr.size()-1) {
            int a = arr[i];
            int b = arr[i+1];
            if(abs(a-b) < k) {
                sum += a;
                sum += b;
                i+=2;
            }
            else i++;
        }
        
        return sum;
    }
};