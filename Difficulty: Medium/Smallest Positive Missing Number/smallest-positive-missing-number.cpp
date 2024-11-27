//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        set<int>s;
        for(auto it : arr) {
            if(it <= 0) continue;
            s.insert(it);
            
        }
  
        vector<int>v;
        for(auto it : s) {
            v.push_back(it);
        }
        sort(v.begin(),v.end());
        if(v.size() == 0) return 1;
        if(v[0] != 1) return 1;
        for(int i = 0 ; i < v.size() ; i++) {
            if(v[i+1] != v[i]+1) return v[i]+1;
        }
        return v[v.size()-1]+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends