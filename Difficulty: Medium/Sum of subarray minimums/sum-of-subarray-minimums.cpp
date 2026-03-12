class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ns(n,n);
        vector<int>ps(n,-1);
        // next smaller 
        stack<int>st;
        
        for(int i = n-1 ; i >= 0 ; i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            
            if(!st.empty()) ns[i] = st.top();
            
            st.push(i);
        }
        
        // prev smaller
        
        stack<int>st2;
        
        for(int i = 0 ; i < n ; i++) {
            while(!st2.empty() && arr[st2.top()] > arr[i]) st2.pop();
            
            if(!st2.empty()) ps[i] = st2.top();
            st2.push(i);
        }
        
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++) {
            // cout << ps[i] << " " << arr[i] << " " << ns[i] << endl;
            
            int l = ns[i]-i;
            int r = i-ps[i];
            
            // cout << l << " " << r << endl;
            sum += l * r * arr[i];
        }
        
        return sum;
        
    }
};