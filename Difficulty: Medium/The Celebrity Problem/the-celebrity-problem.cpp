//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        vector<int>rowSum;
        vector<int>colSum;
        for(int i = 0 ; i < mat.size() ; i++) {
            int sr = 0;
            int sc = 0;
            for(int j = 0 ; j < mat[i].size() ; j++) {
                if(i != j) sr+=mat[i][j];
                if(i != j) sc+=mat[j][i];
            }
            rowSum.push_back(sr);
            colSum.push_back(sc);
        }
        // for(auto it : rowSum) cout<<it<<" ";
        // for(auto it : colSum) cout<<it<<" ";
        int ans = -1;
        for(int i = 0 ; i < rowSum.size() ; i++) {
           if(rowSum[i] == 0) {
               ans = i;
               break;
           }
        }
        int ans2 = -1;
        for(int i = 0 ; i < colSum.size() ; i++) {
            if(colSum[i] == mat.size()-1) {
                ans2 = i;
            }
        }
        if(ans == ans2 && ans != -1 && ans2 != -1) return ans;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends