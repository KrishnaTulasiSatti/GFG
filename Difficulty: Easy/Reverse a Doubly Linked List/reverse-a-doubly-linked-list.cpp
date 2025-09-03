/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* newHead = NULL;
        
        while(curr != NULL) {
            Node* next = curr->next;
            Node* prev = curr->prev;
            curr->prev = next;
            curr->next = prev;
            newHead = curr;
            curr = next;
        }
        
        return newHead;
    }
};