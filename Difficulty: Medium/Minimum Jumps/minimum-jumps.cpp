class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int cnt = 1;
        
        for(int i = 0 ; i < arr.size() ; ) {
            
            int steps = arr[i];
            
            int j = i+1;
            
            int maxi = -1;
            int ind = 0;
            
            
            
            while(steps--) {
                
                if(j >= arr.size()-1) return cnt;
                
                if(arr[j]+j >= maxi && arr[j] != 0) {
                    maxi = arr[j]+j;
                    ind = j;
                }
                
                
                j++;
            }
            
            if(maxi == -1) return -1;
            // cout << maxi << endl;
            
            cnt++;
            
            i = ind;
            
            
        }
        
        return cnt;
        
        
    }
};
