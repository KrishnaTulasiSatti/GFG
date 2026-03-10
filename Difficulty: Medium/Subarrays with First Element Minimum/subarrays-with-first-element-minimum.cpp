class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        vector<int>ns(n,n);
        
        int cnt = 0;
        
        stack<int>st;
        
        for(int i = n-1 ; i >= 0 ; i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            
            if(!st.empty()) ns[i] = st.top();
            
            st.push(i);
        }
        
        for(int i = 0 ; i < n ; i++) {
            // cout << ns[i] << " ";
            cnt += ns[i]-i;
        }
        
        return cnt;
    }
};