class Solution {
  public:
    
    
    string findLargest(vector<int> &arr) {
        // code here
        
        sort(arr.begin(),arr.end(),[](const int a,const int b){
           return to_string(b) + to_string(a) < to_string(a) + to_string(b);
        });
        
        string ans = "";
        
        for(auto it : arr) {
            ans += to_string(it);
        }
        
        int i = 0;
        while(ans[i] == '0') i++;
        
        string res = ans.substr(i);
        
        if(res == "") return "0";
        return res;
    }
};