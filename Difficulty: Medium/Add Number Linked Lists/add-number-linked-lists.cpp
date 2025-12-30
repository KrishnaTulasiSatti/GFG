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
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        
        Node* h1 = reverse(head1);
        Node* h2 = reverse(head2);
        
        Node* temp1 = h1;
        Node* temp2 = h2;
        
        Node* res = new Node(-1);
        Node* temp = res;
        
        int carry = 0;
        
        while(temp1 != NULL || temp2 != NULL || carry == 1) {
            
            int sum = 0;
            if(temp1 != NULL) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if(temp2 != NULL) {
                sum += temp2->data;
                temp2 = temp2->next;
            }
            
            if(carry) sum += carry;
            
            temp->next = new Node(sum % 10);
            temp = temp->next;
            
            carry = sum/10;
            
        } 
        
        Node* ans = reverse(res->next);
        
        while(ans != NULL && ans->data == 0) ans = ans->next;
        
        return ans;
    }
};