/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
  
  bool fun(Node* l,Node* r) {
      
      if(l == NULL && r == NULL) return true;
      
      
      if(l == NULL || r == NULL || l->data != r->data) return false;
      
      
      return fun(l->left,r->right) && fun(l->right,r->left);
      
  }
    bool isSymmetric(Node* root) {
        // Code here
        
        return fun(root->left,root->right);
        
    }
};