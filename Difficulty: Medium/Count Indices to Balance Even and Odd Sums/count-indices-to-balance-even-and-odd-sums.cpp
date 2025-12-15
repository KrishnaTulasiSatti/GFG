class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        
        int cnt = 0;
        
        if(arr.size() == 1) return 1;
        vector<int>even;
        vector<int>odd;
        
        int e = 0, o = 0;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            if(i % 2 == 0) {
                e += arr[i];
                even.push_back(e);
            }
            else {
                o += arr[i];
                odd.push_back(o);
            }
        }
        
        // for(auto it : even) cout << it << " ";
        // cout << endl;
        // for(auto it : odd) cout << it << " ";
        
        int m = even.size(),n = odd.size();
        
        int total = even[m-1];
        if((total-even[0]) == odd[n-1]) cnt++;
        
        for(int i = 1 ; i < arr.size()-1 ; i++) {
            
           
            int ind = i/2;
            int even_sum = 0 , odd_sum = 0;
            
            if(i % 2) {
                
                even_sum = (odd[n-1]-odd[ind])+even[ind];
                odd_sum = (even[m-1]-even[ind]);
                // cout << even_sum << " " << odd_sum << endl;
                if(ind-1 >= 0) odd_sum += odd[ind-1];
            }
            else {
                even_sum = (odd[n-1]-odd[ind-1])+even[ind-1];
                odd_sum = (even[m-1]-even[ind])+odd[ind-1];
            }
            
          //  cout << even_sum << " " << odd_sum << " " << i <<  endl;
            
            if(even_sum == odd_sum) cnt++;
            
        }
        
        if(arr.size() % 2) {
            if(total-arr[arr.size()-1] == odd[n-1]) cnt++;
        }
        else {
            total = odd[n-1];
            if(total-arr[arr.size()-1] == even[m-1]) cnt++;
        }
        
        return cnt;
        
        
        
        
    }
};