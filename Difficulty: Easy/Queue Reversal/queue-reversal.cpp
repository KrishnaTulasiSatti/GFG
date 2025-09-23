class Solution {
  public:
  
    void fun(queue<int>&q, int t) {
        
        
        
        if(q.empty()) return;
        
        q.pop();
        
        fun(q,q.front());
        
        q.push(t);
        
        
        
    }
    void reverseQueue(queue<int> &q) {
        
        // code here
        fun(q,q.front());
        
    }
};