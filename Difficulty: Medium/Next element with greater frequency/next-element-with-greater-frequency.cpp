class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        
        stack<pair<int,int>>st;
        
        vector<int>ans(arr.size(),-1);
        
        unordered_map<int,int>m;
        
        for(auto it : arr) m[it]++;
        
        for(int i = arr.size()-1 ; i >= 0 ; i--) {
            
            while(!st.empty() && st.top().second <= m[arr[i]]) st.pop();
            
            if(!st.empty()) ans[i] = st.top().first;
            
            st.push({arr[i],m[arr[i]]});
        }
        
        return ans;
    }
};
