/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
  int maxi = -1;
  
  void fun(Node* root,int k) {
      if(root == NULL) return;
      
      if((root->data) <= k) {
          maxi = max(maxi,root->data);
          if(root->right) fun(root->right,k);
      }
      else {
          
          if(root->left) fun(root->left,k);
      }
  }
    int findMaxFork(Node* root, int k) {
        // code here
        fun(root,k);
        return maxi;
    }
};