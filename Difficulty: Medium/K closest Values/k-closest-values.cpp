/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    priority_queue<pair<int,int>>pq;
  
    void fun(Node* root,int t,int k) {
        
        if(root == NULL) return;
        
        fun(root->left,t,k);
        
        pq.push({abs(t-(root->data)),root->data});
        
        if(pq.size() > k) pq.pop();
        
        fun(root->right,t,k);
        
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        
        fun(root,target,k);
        
        vector<int>res;
        
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
        
    }
};