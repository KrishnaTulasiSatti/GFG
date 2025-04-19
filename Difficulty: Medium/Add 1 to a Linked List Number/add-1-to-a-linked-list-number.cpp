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
        head = reverse(head);
        Node* res = new Node(-1);
        
        Node* temp = res;
        
        Node* temp1 = head;
        int carry = 1;
        
        while(temp1 != NULL || carry) {
            int sum = carry;
            
            if(temp1) sum+=temp1->data;
            
            Node* newnode = new Node(sum%10);
            carry = sum/10;
            
            temp->next = newnode;
            temp = newnode;
            
            if(temp1) temp1 = temp1->next;
        }
        
        res = res->next;
        res = reverse(res);
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
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends