/* Structure for Tree Node
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
    
    int fun(Node* root) {
        if(root == NULL) return 0;
        
        int left = fun(root->left);
        int right = fun(root->right);
        
        int val = root->data;
        
        root->data = left + right;
        
        return val + left + right;
    }
    void toSumTree(Node *root) {
        // code here
        
        int sum = fun(root);
        
    }
};