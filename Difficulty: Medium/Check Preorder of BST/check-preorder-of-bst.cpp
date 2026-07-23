class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        vector<int>ng(n,-1);
        
        stack<int>st;
        
        for(int i = n-1 ; i >= 0 ; i--) {
            
           while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
           
           if(st.empty()) ng[i] = -1;
           else ng[i] = st.top();
           
           st.push(i);
        }
        
        // for(auto& it : ng) {
        //     cout << it << " ";
        // }
        
        // cout << endl;
        
        vector<int>fs(n,-1);
        
        vector<int>suff(n,-1);
        suff[n-1] = n-1;
        
        for(int i = n-2 ; i >= 0 ; i--) {
            if(arr[suff[i+1]] < arr[i]) {
                suff[i] = suff[i+1];
            }
            else suff[i] = i;
        }
        
        // for(auto& it : suff) cout << it << " ";
        // cout << endl;
        
        for(int i = 0 ; i < n ; i++) {
            int low = i+1;
            int high = n-1;
            
            int ans = i;
            
            while(low <= high) {
                int mid = (low + high)/2;
                if(arr[suff[mid]] < arr[i]) {
                    ans = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
            
            fs[i] = ans;
        }
        
        // for(auto& it : fs) cout << it << " ";
        
        for(int i = 0 ; i < n ; i++) {
            if(ng[i] == -1) continue;
            if(ng[i] < fs[i]) return false;
        }
        
        return true;
        
        
        
    }
};