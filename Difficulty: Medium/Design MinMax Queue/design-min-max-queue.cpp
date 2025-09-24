class SpecialQueue {

  public:
  
    queue<int>q;
    
    priority_queue<int>max_heap;
    
    priority_queue<int,vector<int>,greater<int>>min_heap;
    
    unordered_map<int,int>m1;
    unordered_map<int,int>m2;
    

    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        min_heap.push(x);
        max_heap.push(x);
    }

    void dequeue() {
        // Remove element from the queue
        int f = q.front();
        
        m1[f]++;
        m2[f]++;
        
        q.pop();
        
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        
        while(!min_heap.empty() && m1[min_heap.top()] > 0) {
            m1[min_heap.top()]--;
            min_heap.pop();
        } 
        
        return min_heap.top();
    }

    int getMax() {
        // Get maximum element
        
        while(!max_heap.empty() && m2[max_heap.top()] > 0) {
            m2[max_heap.top()]--;
            max_heap.pop();
        } 
        
        return max_heap.top();
        
    }
};