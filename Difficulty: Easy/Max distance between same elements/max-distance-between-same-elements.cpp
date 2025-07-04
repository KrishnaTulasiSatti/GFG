//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,vector<int>>m;
        for(int i = 0 ; i < arr.size() ; i++) {
            m[arr[i]].push_back(i);
        }
        
        int maxi = INT_MIN;
        for(auto it : m) {
            int n = it.second.size();
            int a = it.second[0];
            int b = it.second[n-1];
           // cout<<a<<" "<<b<<endl;
            maxi = max(maxi,abs(a-b));
        }
        return maxi;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends