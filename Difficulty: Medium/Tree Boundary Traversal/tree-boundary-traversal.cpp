/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    vector<int>res;
    
    void left_node(Node* root) {
    
        
        Node* temp = root->left;
        
        while(temp) {
            
            if(!(temp->left == NULL && temp->right == NULL)) {
                res.push_back(temp->data);
            }
            
            if(temp->left) temp = temp->left;
            else temp = temp->right;
        }
    
        
    }
    
    void right_node(Node* root) {
        
         
        Node* temp = root->right;
        
        vector<int>v;
        
        while(temp) {
            
            if(!(temp->left == NULL && temp->right == NULL)) {
                v.push_back(temp->data);
            }
            
            if(temp->right) temp = temp->right;
            else temp = temp->left;
        }
        
        for(int i = v.size()-1 ; i >= 0 ; i--) res.push_back(v[i]);
        
    }
    
    void bottom_node(Node* root) {
        
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) {
            res.push_back(root->data);
            return;
        }
        
        bottom_node(root->left);
        bottom_node(root->right);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        res.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL) return res;
        left_node(root);
        bottom_node(root);
        right_node(root);
        
        return res;
        
        
    }
};