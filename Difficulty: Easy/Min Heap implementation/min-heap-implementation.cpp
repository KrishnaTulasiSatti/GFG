class minHeap {
  private:
    // Initialize your data members

  public:
  
    priority_queue<int,vector<int>,greater<>>pq;

    void push(int x) {
        // Insert x into the heap
        pq.push(x);
    }

    void pop() {
        // Remove the top (minimum) element
        pq.pop();
    }

    int peek() {
        // Return the top element or -1 if empty
        if(pq.empty()) return -1;
        return pq.top();
    }

    int size() {
        // Return the number of elements in the heap
        return (int)pq.size();
        
    }
};