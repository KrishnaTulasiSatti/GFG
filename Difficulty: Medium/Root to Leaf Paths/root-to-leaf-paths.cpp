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
    
    vector<vector<int>>ans;
    
    void fun(Node* root,vector<int>& temp) {
        
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) {
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->data);
        fun(root->left,temp);
        fun(root->right,temp);
        
        temp.pop_back();
        
        
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<int>temp;
        
        fun(root,temp);
        
        return ans;
        
    }
};