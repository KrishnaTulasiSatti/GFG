class Solution {
  public:
    
    vector<string>res;
    
    void fun(vector<int> &arr,int i,int n,string temp,unordered_map<int,string>m) {
        
        if(i >= n) {
            res.push_back(temp);
            return;
        }
        
        if(arr[i] == 1 || arr[i] == 0) fun(arr,i+1,n,temp,m);
        
        // pick
        
        for(int j = 0 ; j < m[arr[i]].size() ; j++) {
            string s = m[arr[i]];
            temp += s[j];
            fun(arr,i+1,n,temp,m);
            temp.pop_back();
        }
        
    }
    vector<string> possibleWords(vector<int> &arr) {
        
        // code here
        
        
        unordered_map<int,string>m;
        
        vector<string>v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        
        for(int i = 0 ; i < v.size() ; i++) {
            m[i+2] = v[i];
        }
        
        int n = arr.size();
        
        string temp = "";
        
        fun(arr,0,n,temp,m);
        
        return res;
        
    }
};