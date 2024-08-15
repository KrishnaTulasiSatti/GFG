//{ Driver Code Starts
// Initial template for C++

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
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
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
      head = prev;
      return head;
  }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* h1 = reverse(head);
        Node* temp = h1;
        while(true && temp->next != NULL) {
             int x = temp->data;
             if(temp->data+1 < 10) {
                 temp->data+=1;
                 break;
             }
             else {
                 temp->data = 0;
                 temp = temp->next;
             }
        }
        if(temp->next == NULL) {
            temp->data = 0;
            temp->next = new Node(1);
        }
        Node* res = reverse(h1);
        return res;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends