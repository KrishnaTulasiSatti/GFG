class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            
            int diff = abs(arr[i]-x);
            
            if(diff == 0) continue;
            
            pq.push({diff,-1*arr[i]});
            
        }
        
        vector<int>res;
        
        while(k--) {
            res.push_back(-1*pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};