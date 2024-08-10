//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to rotate a linked list.
    Node* reverse(Node* head,Node* prev1) {
        Node* curr = head;
        Node* next = head;
        Node* prev = NULL;
        while(next != prev1) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    Node* rotate(Node* head, int k) {
        // Your code here
        if(head == NULL) return NULL;
    
        Node* temp = head;
        int i = 0;
        while(i < k) {
            temp = temp->next;
            i++;
        }
        Node* h1 = reverse(head,temp);
        Node* h2 = reverse(temp,NULL);
        Node* newHead = h1;
        Node* t = h1;
        for(int i = 0 ; i < k-1 ; i++) {
            t = t->next;
        }
        t->next = h2;
        newHead = reverse(newHead,NULL);
      //  cout<<temp->data;
        return newHead;
        
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends