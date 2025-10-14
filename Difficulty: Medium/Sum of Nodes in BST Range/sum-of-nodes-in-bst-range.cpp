/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    int fun(Node* root,int l,int r) {
        
        if(root == NULL) return 0;
        
        int a = 0;
        int b = 0;
        
        a = fun(root->left,l,r);
        
        b = fun(root->right,l,r);
        
        if(root->data >= l && root->data <= r) return root->data + a+ b;
        
        return a + b;
        
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        
        int res = fun(root,l,r);
        
        return res;
        
    }
};
