class Solution {
  public:
  static bool cmp (const int& a,const int& b) {
        string x = to_string(a);
        string y = to_string(b);
        
        return x+y > y+x;
  }
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end(),cmp);
        
        string res = "";
        
        for(auto it : arr) {
            res += to_string(it);
        }
        
        int i = 0;
        
        while(res[i] == '0') i++;
        
        if(i == res.size()) return "0";
        return res;
        
    }
};