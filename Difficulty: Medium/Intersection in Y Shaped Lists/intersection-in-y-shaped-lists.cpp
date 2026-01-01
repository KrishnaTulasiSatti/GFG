/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        unordered_map<Node*,int>m;
        
        Node* temp = head1;
        
        while(temp != NULL) {
            m[temp]++;
            temp = temp->next;
        }
        
        temp = head2;
        
        while(temp != NULL) {
            if(m.find(temp) != m.end()) return temp;
            temp = temp->next;
        }
        
        return NULL;
    }
};