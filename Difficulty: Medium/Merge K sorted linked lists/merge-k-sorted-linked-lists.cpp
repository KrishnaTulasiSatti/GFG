/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


class Solution {
  public:
  
    
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
        
        for(auto it : arr) {
            
            pq.push({it->data,it});
        }
        
        Node* res = new Node(-1);
        
        Node* temp = res;
        
        while(!pq.empty()) {
            
            auto top = pq.top();
            pq.pop();
            
            int val = top.first;
            
            Node* curr = top.second;
            top.second = top.second->next;
            curr->next = NULL;
            
            temp->next = curr;
            temp = temp->next;
            
            if(top.second) pq.push({top.second->data,top.second});
            
            
            
        }
        
        return res->next;
        
        
        
        
    }
};