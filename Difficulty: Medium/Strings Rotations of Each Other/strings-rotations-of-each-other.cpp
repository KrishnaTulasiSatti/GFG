class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        s1 += s1;
        
        return s1.find(s2) < s1.size();

    
    }
};