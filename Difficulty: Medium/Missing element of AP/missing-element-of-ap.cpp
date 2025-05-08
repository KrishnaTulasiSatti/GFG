//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int diff = 0;
        
        unordered_map<int,int>m;
        
        for(int i = 0 ; i < arr.size()-1 ; i++) {
            diff = abs(arr[i]-arr[i+1]);
            m[diff]++;
        }
        
        int maxi = 0;
        int d1 = 0;
        
        for(auto it : m) {
            if(it.second > maxi) {
                maxi = it.second;
                d1 = it.first;
            }
        }
        
        for(int i = 0 ; i < arr.size()-1 ; i++) {
            int d2 = abs(arr[i]-arr[i+1]);
            
            if(d1 != d2) {
                return arr[i]+d1;
            }
        }
        
        return arr[arr.size()-1]+d1;
        
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends