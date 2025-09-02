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
    Node* swapKth(Node* head, int k) {
        // code here
        int i = 1;
        
        Node* temp = head;
        
        int len = 0;
        
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        
        
        int j = 1;
        
        int kf = 0;
        int kl = 0;
        
        // int len = 0;
        temp = head;
        
        while(temp != NULL) {
            if(i == k) {
                kf = temp->data;
            }
            
            if(j == (len)-(k-1)) {
                kl = temp->data;
            }
            
            i++;
            j++;
            
            temp = temp->next;
        }
        
        temp = head;
        
        if(kf == 0 || kl == 0) return head;
        
        i = 1,j = 1;
        
        while(temp != NULL) {
            if(i == k) {
               temp->data = kl;
            }
            
            if(j == (len)-(k-1)) {
                temp->data = kf;
            }
            
            i++;
            j++;
            
            temp = temp->next;
        }
        
        return head;
        
        
    }
};