class Solution {
  public:
  
 string add2num(string a,string b) {
     
     reverse(a.begin(),a.end());
     reverse(b.begin(),b.end());
     
     int carry = 0;
     
     int i = 0,j =0 ;
     
     string res = "";
     
   
     while(i < a.size() || j < b.size() || carry) {
         int sum = 0;
         
         if(i < a.size()) sum += a[i++]-'0';
         if(j < b.size()) sum += b[j++]-'0';
         
         sum += carry;
         
       
         
         carry = sum/10;
         
         res += (sum % 10)+'0';
         
         
         
     }
     
     reverse(res.begin(),res.end());
     
     return res;
     
     
 }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        
        string s1,s2;
        
        for(int i = 0 ; i < arr.size() ; i++) {
           if(i % 2 == 0) s1 += (arr[i]+'0');
           else s2 += (arr[i]+'0');
        }
        
        string res = add2num(s1,s2);
        
        int i = 0;
        
        while(res[i] == '0') i++;
        
        res = res.substr(i);
        
        return res;
    }
};