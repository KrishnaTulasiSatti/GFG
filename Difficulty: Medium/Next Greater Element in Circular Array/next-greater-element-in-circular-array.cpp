class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        stack<int>st;
        
        
        vector<int>ans;
        
        
        
        for(int i = 2*arr.size()-1 ; i >= 0 ; i--) {
            
            while(!st.empty() && st.top() <= arr[i % arr.size()]) {
                st.pop();
            }
            
            if(i < arr.size()) {
                if(!st.empty()) ans.push_back(st.top());
                else ans.push_back(-1);
            }
            
            st.push(arr[i % arr.size()]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};