/*
class Node {
  public:
    int data;
    Node *next;

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
    bool isPalindrome(Node *head) {
        //  code here
        
        if(head->next == NULL || head == NULL) return head;
        
        Node* slow = head;
        Node* fast = head;
        
        Node* prev = NULL;
        
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        Node* temp2 = reverse(slow);
        
        Node* temp1 = head;
        
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->data != temp2->data) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return true;
        
    }
};