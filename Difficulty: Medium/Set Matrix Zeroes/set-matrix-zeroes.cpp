//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>>z;
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[i].size() ; j++) {
                if(mat[i][j] == 0) {
                    z.push_back({i,j});
                }
            }
        }
        
        for(int i = 0 ; i < z.size() ; i++) {
            for(int j = 0 ; j < m ; j++) {
                mat[z[i].first][j] = 0;
            }
             for(int j = 0 ; j < n ; j++) {
                mat[j][z[i].second] = 0;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends