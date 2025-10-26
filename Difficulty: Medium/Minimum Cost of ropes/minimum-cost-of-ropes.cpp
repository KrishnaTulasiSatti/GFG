class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int mini = 0;
        
        for(auto it : arr) pq.push(it);
        
        while(pq.size() > 1) {
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();
            
           // cout << t1 << " " << t2 << endl;
            pq.push(t1+t2);
            
            mini += (t1+t2);
            
        }
        
        return mini;
        
        
    }
};