/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    vector<int>v;
    unordered_map<int,Node*>m;
    
    void fun(Node* root) {
        if(root == NULL) return;
        fun(root->left);
        m[root->data] = root;
        v.push_back(root->data);
        fun(root->right);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        
        fun(root);
        
        vector<Node*>res(2);
        
        int lb = lower_bound(v.begin(),v.end(),key)-v.begin()-1;
        
        if(lb < 0) res[0] = NULL;
        else res[0] = m[v[lb]];
        
        int ub = upper_bound(v.begin(),v.end(),key)-v.begin();
        
        if(ub == v.size()) res[1] = NULL;
        else res[1] = m[v[ub]];
        
        
        return res;
        
    }
};