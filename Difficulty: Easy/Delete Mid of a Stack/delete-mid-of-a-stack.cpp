//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    void fun(stack<int>&s,int i,int mid) {
        if(i == mid) {
            s.pop();
            return;
        }
        int a = s.top();
        s.pop();
        fun(s,i+1,mid);
        s.push(a);
        
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int size = s.size();
       // cout<<size<<endl;
        int mid = size/2;
       // if(size % 2) mid--;
      //    cout<<mid<<endl;
        fun(s,0,mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends