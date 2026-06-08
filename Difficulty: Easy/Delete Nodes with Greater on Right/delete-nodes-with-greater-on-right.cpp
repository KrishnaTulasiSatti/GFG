/* Structure of a Linked List node
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
    
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* next = head;
        
        Node* prev = NULL;
        
        while(next != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    Node *compute(Node *head) {
        // code here
        
        Node* h = reverse(head);
        
        Node* maxi = new Node(-1);
        Node* t = maxi;
        
        Node* temp = h;
        
        while(temp != NULL) {
            
            Node* curr = temp;
            temp = temp->next;
            curr->next = NULL;
            
            if(curr->data >= t->data) {
                t->next = curr;
                t = t->next;
            }
            
            
        }
        
        Node* res = reverse(maxi->next);
        return res;
        
        
        
    }
};