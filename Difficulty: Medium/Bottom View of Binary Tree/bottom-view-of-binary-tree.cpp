/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        map<int,int>m;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++) {
                
                auto top = q.front();
                m[top.second] = top.first->data;
                
                q.pop();
                
                if(top.first->left) q.push({top.first->left,top.second-1});
                if(top.first->right) q.push({top.first->right,top.second+1});
                
                
            }
        }
        
        vector<int>res;
        
        for(auto it : m) {
            res.push_back(it.second);
        }
        return res;
        
    }
};