//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>>& mat) {
        // code here
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[0].size() ; j++) {
                if(mat[i][j] == 1) {
                    m1[i]++;
                    m2[j]++;
                }
            }
        }
        
        for(int i = 0 ; i < mat.size() ; i++) {
            if(m1[i] > 0) {
                for(int j = 0 ; j < mat[0].size() ; j++) {
                    mat[i][j] = 1;
                }
            }
        }
        
        for(int j = 0 ; j < mat[0].size() ; j++) {
            if(m2[j] > 0) {
                for(int i = 0 ; i < mat.size() ; i++){
                    mat[i][j] = 1;
                }
            }
        }
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int> > matrix(row);
        for (int i = 0; i < row; i++) {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.booleanMatrix(matrix);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends