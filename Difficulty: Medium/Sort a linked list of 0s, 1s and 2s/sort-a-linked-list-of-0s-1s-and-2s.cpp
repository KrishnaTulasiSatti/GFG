/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        
        Node* temp = head;
        Node* zh = new Node(0);
        Node* z = zh;
        Node* oh = new Node(1);
        Node* o = oh;
        Node* th = new Node(2);
        Node* t = th;
        
        
        
        
        while(temp != NULL) {
            
            Node* curr = temp;
            temp = temp->next;
            
            curr->next = NULL;
            
            if(curr->data == 1) {
                o->next = curr;
                o = o->next;
            } 
            else if(curr->data == 0) {
                z->next = curr;
                z = z->next;
            }
            else {
                t->next = curr;
                t = t->next;
            }
            
        }
        
        z->next = (oh->next) ? (oh->next) : (th->next);
        o->next = th->next;
        
        return zh->next;
        
       
        
    }
};