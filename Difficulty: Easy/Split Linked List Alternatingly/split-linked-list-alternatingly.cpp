//{ Driver Code Starts
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


// } Driver Code Ends
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
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        if(head->next == NULL) return {head,NULL};
        struct Node* h1 = new Node(head->data);
        struct Node* h2 = new Node(head->next->data);
        if(head->next->next == NULL) return {h1,h2};
        struct Node* temp = head->next->next;
        struct Node* t1 = h1;
        struct Node* t2 = h2;
        int flag = 0;
        while(temp != NULL) {
           // cout<<temp->data<<endl;
            if(flag == 0) {
                h1->next = new Node(temp->data);
                h1 = h1->next;
                flag = 1;
            }
            else {
                h2->next = new Node(temp->data);
                h2 = h2->next;
                flag = 0;
            }
            temp = temp->next;
        }
        return {t1,t2};
        
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends