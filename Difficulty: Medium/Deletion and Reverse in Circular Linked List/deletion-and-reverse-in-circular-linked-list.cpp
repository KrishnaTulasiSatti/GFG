//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        if(head == NULL || head->next == head) return head;
        Node* curr = head;
        Node* prev = NULL;
        Node* next = head;
        do{
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }while(next != head);
        head->next = prev;
        head = prev;
        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        Node* temp = head;
        Node* t1 = head;
        if(temp->next == head && key == temp->data) {
            delete temp;
            return NULL;
        }
        if(temp->data == key){
            while(t1->next != head) {
                t1 = t1->next;
            }
            t1->next = head->next;
            Node* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }
        temp = head;
        Node* prev = head;
        while(temp->next != head) {
            if(temp->data == key) {
                prev->next = temp->next;
                break;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends