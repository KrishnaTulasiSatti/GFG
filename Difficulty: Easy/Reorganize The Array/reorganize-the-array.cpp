//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int frq[100001] = {0};
        vector<int>res;
        for(auto it : arr) {
            if(it == -1) continue;
            else frq[it] = 1;
        }
        for(int i = 0 ; i < arr.size() ; i++) {
            if(frq[i] == 1) res.push_back(i);
            else res.push_back(-1);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends