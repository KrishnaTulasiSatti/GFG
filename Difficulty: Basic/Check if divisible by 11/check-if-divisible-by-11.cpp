// User function template for C++
class Solution {
  public:

    int divisibleBy11(string s) {
        // Your Code Here
          
        int rem = 0;
        
        for(int i = 0 ; i < s.size() ; i++) {
            rem = (rem * 10 + (s[i]-'0')) % 11;
        }
        
        return rem == 0;
    
    }
};