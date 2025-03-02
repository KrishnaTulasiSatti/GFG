//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        multiset<int>s;
        
        for(int i = 0 ; i < k ; i++) {
            s.insert(arr[i]);
        }
        
        vector<int>res;
        int l = 0;
        int r = k;
        res.push_back(*s.rbegin());
        
        while(r < arr.size()) {
            s.erase(s.find(arr[l]));
            s.insert(arr[r]);
            res.push_back(*s.rbegin());
            l++;
            r++;
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends