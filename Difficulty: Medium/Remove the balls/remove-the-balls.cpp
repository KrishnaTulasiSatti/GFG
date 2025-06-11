class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>>st;
        
        st.push({color[0],radius[0]});
        
        for(int i = 1 ; i < color.size() ; i++) {
            if(!st.empty()) {
                auto top = st.top();
            
                if(top.first != color[i] || top.second != radius[i]) {
                    st.push({color[i],radius[i]});
                }
                else {
                    st.pop();
                }
            }
            else {
                st.push({color[i],radius[i]});
            }
        }
        
        return st.size();
    }
};