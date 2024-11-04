//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        
        unordered_map<int,vector<int>>m;
        for(int i = 0 ; i < arr.size() ; i++) {
           m[arr[i]].push_back(i);
        }
        vector<vector<int>>res;
        for(int i = 0 ; i < arr.size() ; i++) {
            int a = arr[i];
            for(int j = i+1 ; j < arr.size() ; j++) {
                int s = a+arr[j];
                if(m[-1*s].size() != 0) {
                    for(auto it : m[-1*s]){
                        int p = -1,q = -1,r = -1;
                         vector<int>ans;
                        if((p != 1 || q != 1 || r != 1) && it > j) {
                            ans.push_back(i);
                            ans.push_back(j);
                            ans.push_back(it);
                            p = 1,q = 1,r = 1;
                            res.push_back(ans);
                        }
                        
                    }
                }
                
                
            }
           //  res.push_back(ans);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends