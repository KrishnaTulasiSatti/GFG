class Solution {
  public:
  
  int fact(int a) {
      
      int pro = 1;
      
      for(int i = 1; i <= a ; i++) {
          pro *= i;
      }
      
      
      return pro;
  }
    int vowelCount(string& s) {
        // code here
        int cnt = 0;
        
        unordered_map<char,int>m;
        for(auto it : s) {
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                m[it]++;
            }
        }
        
        int a = m.size();
        
        
        if(a == 0) return 0;
        
        cnt = fact(a);
        
        for(auto it : m) {
            cnt *= it.second;
        }
        
        return cnt;
        
        
    }
};