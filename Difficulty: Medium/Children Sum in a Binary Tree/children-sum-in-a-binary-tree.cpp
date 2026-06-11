/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    
    
    bool isSumProperty(Node *root) {
        // code here
        
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty()) {
            
            auto top = q.front();
            q.pop();
            
            int left = 0;
            int right = 0;
            
            if(top->left) {
                q.push(top->left);
                left = top->left->data;
            }
            
            if(top->right) {
                q.push(top->right);
                right = top->right->data;
            }
            
            if(!top->left && !top->right) continue;
            
            if(top->data != (left+right)) return false;
        }
        
        return true;
    }
};