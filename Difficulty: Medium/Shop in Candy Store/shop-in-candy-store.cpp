class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        
        int i = 0;
        int j = prices.size()-1;
        
        int mini = 0;
        
        while(i <= j) {
            mini += prices[i++];
            j-=k;
        }
        
        i = 0;
        j = prices.size()-1;
        int maxi = 0;
        
        while(i <= j) {
            maxi += prices[j--];
            i+=k;
        }
        
        return {mini,maxi};
    }
};