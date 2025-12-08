class Solution {
  public:
    int transform(string A, string B) {
        // code here.
        
        string temp1 = A;
        string temp2 = B;
        
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        
        if(temp1 != temp2) return -1;
        
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        
        
        int i = 0;
        int j = 0;
        
        int cnt = 0;
        
        int n = A.size();
        
        while(j < B.size() && i < A.size()) {
            if(A[i] == B[j]) {
                i++;
                j++;
            }
            else {
                cnt++;
                i++;
            }
        }
        
        return cnt;
      
    }
};
