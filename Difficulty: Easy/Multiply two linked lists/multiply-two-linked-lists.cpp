//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to create a new Node with given data */
struct Node *newNode(int data) {
    struct Node *new_Node = new Node(data);

    return new_Node;
}

Node *reverse(Node **r) {
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node **head_ref, int new_data) {
    /* allocate Node */
    struct Node *new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node) {
    struct Node *temp;
    while (Node != NULL) {

        temp = Node;
        Node = Node->next;
        free(temp);
    }
}


// } Driver Code Ends
/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        string str1 = "";
        string str2 = "";
        Node* t1 = first;
        Node* t2 = second;
        while(t1 != NULL) {
            str1+=(t1->data)+'0';
            t1 = t1->next;
        }
        while(t2 != NULL) {
            str2+=(t2->data)+'0';
            t2= t2->next;
        }
        //cout<<str1<<" "<<str2<<endl;
        const int mod = 1e9+7;
        long long n1 = (stol(str1)) % mod;
        long long n2 = (stol(str2)) % mod;
        long long pro = n1*n2;
        return pro % mod;
        
    }
};

//{ Driver Code Starts.

// A utility function to print a linked list
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        struct Node *first = NULL;
        struct Node *second = NULL;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }
        for (int i = 0; i < arr.size(); i++) {
            push(&first, arr[i]);
        }
        vector<int> brr;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number1;
        while (ss2 >> number1) {
            brr.push_back(number1);
        }
        for (int i = 0; i < brr.size(); i++) {
            push(&second, brr[i]);
        }
        reverse(&first);
        reverse(&second);
        solution ob;
        long long res = ob.multiplyTwoLists(first, second);
        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}

// } Driver Code Ends