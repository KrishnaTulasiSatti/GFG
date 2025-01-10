//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int>ans;
        
        unordered_map<int,int>m;
        for(int i = 0 ; i < k ; i++) {
            m[arr[i]]++;
        }
        ans.push_back(m.size());
        
        int l = 0;
        int r = k;
        while(r < arr.size()) {
            m[arr[r]]++;
            m[arr[l]]--;
            if(m[arr[l]] == 0) m.erase(arr[l]);
            ans.push_back(m.size());
            r++;
            l++;
        }
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends