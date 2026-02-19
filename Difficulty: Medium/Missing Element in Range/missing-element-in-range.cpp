class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        vector<int>frq(high-low+1,0);
        
        for(auto it : arr) {
            if(it >= low && it <= high) {
                frq[it-low] = 1;
            }
        }
        
        vector<int>ans;
        
        for(int i = 0 ; i < frq.size() ; i++) {
            if(frq[i] == 0) {
                ans.push_back(i+low);
            }   
        }
        
        return ans;
    }
};