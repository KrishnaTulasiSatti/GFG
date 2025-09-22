// User function Template for C++

class Solution {

  public:
    vector<int> help_classmate(vector<int> arr, int n) {
        // Your code goes here
        stack<int>st;
        
        vector<int>res(n);
        
        for(int i = arr.size()-1 ; i >= 0 ; i--) {
            
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            
            st.push(arr[i]);
            
        }
        
        return res;
    }
};