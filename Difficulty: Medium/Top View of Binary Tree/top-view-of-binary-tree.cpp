/*
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
    vector<int> topView(Node *root) {
        // code here
        
        map<int,int>m;
        
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        m[0] = root->data;
        
        while(!q.empty()) {
            int size = q.size();
            
            
            for(int i = 0 ; i < size ; i++) {
                
                auto top = q.front();
                q.pop();
                
                int dist = top.second;
                Node* temp = top.first;
                
                if(temp->left) {
                    q.push({temp->left,dist-1});
                    if(m.find(dist-1) == m.end()) 
                        m[dist-1] = temp->left->data;
                }
                if(temp->right) {
                    q.push({temp->right,dist+1});
                    if(m.find(dist+1) == m.end()) 
                        m[dist+1] = temp->right->data;
                }
            }
            
        }
        
        vector<int>ans;
        
        for(auto it : m) {
            ans.push_back(it.second);
        }
        
        return ans;
        
        
    }
};