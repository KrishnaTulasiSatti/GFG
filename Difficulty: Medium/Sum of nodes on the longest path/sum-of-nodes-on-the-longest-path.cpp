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
  int maxlen = 0;
  int maxi = 0;
  void fun(Node* root,int len,int sum) {
      
      if(root == NULL) return;
      if(root->left == NULL && root->right == NULL) {
          
        //  cout << len << " " << maxlen << endl;
          
          if(len > maxlen) {
             maxlen = len;
             maxi = sum+(root->data);
             
            // cout << maxi << " " << endl;
          }
          else if(len == maxlen) {
              maxi = max(maxi,sum+(root->data));
          }
          
          return;
      }
      
      if(root->left != NULL) fun(root->left,len+1,sum+(root->data));
      
      if(root->right != NULL) fun(root->right,len+1,sum+(root->data));
      
      
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        
        fun(root,0,0);
        
        return maxi;
        
    }
};