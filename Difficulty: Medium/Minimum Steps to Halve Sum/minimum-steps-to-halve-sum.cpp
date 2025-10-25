class Solution {
  public:
    int minOperations(vector<int>& arr) {
        
        // code here
        
        int mini = 0;
        
        priority_queue<double>pq;
        
        for(auto it : arr) {
            pq.push(it);
        }
    
        
        double init_sum = accumulate(arr.begin(),arr.end(),0);
        
        // cout << init_sum << endl;
        
        double sum = init_sum;
        
        int cnt = 0;
        
        init_sum /= 2.0;
        
        // cout << init_sum << endl;
        
        while(sum > init_sum) {
            
            double top = pq.top();
            pq.pop();
            
            // cout << top << "-->";
            
            double val = top/2.0;
            
            // cout << val << "-->";
            
            sum -= val;
            
            // cout << sum << endl;
            
            pq.push(val);
            
            cnt++;
        
            
        }
        
       
        
        
       // cout << init_sum << endl;
        
        return cnt;
        
        
    }
};