class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        
        // code here
        
        
        if(type == 1) {
            while(k--) {
                int l = dq.back();
                dq.pop_back();
                dq.push_front(l);
            }
            
        }
        else {
            while(k--) {
                int f = dq.front();
                dq.pop_front();
                dq.push_back(f);
            }
        }
        
        
        
        
    }
};