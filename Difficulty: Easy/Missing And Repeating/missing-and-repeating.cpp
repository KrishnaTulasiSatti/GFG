class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        long long s = 0;

        for(auto& it : arr) s += it;
        
        long long sn = (1LL * n * (n+1))/2;
        
        long long s2 = 0;
        
        for(auto& it : arr) s2 += 1LL * it * it;
        
        long long sn2 = (1LL * n * (n+1) * (2*n+1))/6;
        
        
        long long a = (s-sn); // x-y
        long long b = (s2-sn2)/(s-sn); // x+y
        
        int repeat = (a+b)/2; // x-y+x+y;
        int missing = (b-a)/2; // (x+y-x+y);
        
        return {repeat,missing};
    }
};