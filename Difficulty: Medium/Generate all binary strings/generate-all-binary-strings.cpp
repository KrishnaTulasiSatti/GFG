class Solution {
  public:
    vector<string>res;
    
    void fun(int n,int i,string temp) {
        
        if(i == n) {
            
            res.push_back(temp);
            return;
        }
    
        
        // not pick
        
        fun(n,i+1,temp+'0');
        
        // pick
        
        fun(n,i+1,temp+'1');
        
    }
    
    vector<string> binstr(int n) {
        // code here
        
        fun(n,0,"");
        
        return res;
        
    }
};