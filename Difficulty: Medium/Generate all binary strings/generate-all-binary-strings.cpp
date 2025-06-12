// User function Template for C++

class Solution {
  public:
  
  vector<string>res;
  
  void fun(string s,int i,int num) {
      if(i == num) {
          res.push_back(s);
          return;
      }
      
      // We can pick '0';
      
      fun(s+'0',i+1,num);
      
      // We cannot pick '1' if we already picked '1' in before step
      
      if(i == 0) fun(s+'1',i+1,num);
      
      if(i >= 1 && s[i-1] != '1') {
          fun(s+'1',i+1,num);
      }
  }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        string s = "";
        fun(s,0,num);
        
        return res;
        
    }
};