class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(holes.begin(),holes.end());
        
        sort(mices.begin(),mices.end());
        
        int maxi = INT_MIN;
        
        for(int i = 0 ; i < holes.size() ; i++) {
            maxi = max(maxi,abs(holes[i]-mices[i]));
        }
        return maxi;
    }
};