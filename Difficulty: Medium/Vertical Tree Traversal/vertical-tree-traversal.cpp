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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        
        map<int,vector<int>>m;
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        
        while(!q.empty()) {
            
            auto top = q.front();
            int level = top.second;
            Node* temp = top.first;
            m[level].push_back(temp->data);
            
            q.pop();
            
            if(temp->left) q.push({temp->left,level-1});
            if(temp->right) q.push({temp->right,level+1});
            
        }
        
        vector<vector<int>>res;
        
        for(auto it : m) {
            res.push_back(it.second);
        }
        
        return res;
    }
};