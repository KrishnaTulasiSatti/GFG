//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
void fun(vector<vector<int>>&image,int sr,int sc,int nc,int oc) {
      if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return;
      if(image[sr][sc] != oc) return;
      image[sr][sc] = nc;
      fun(image,sr,sc-1,nc,oc);
      fun(image,sr-1,sc,nc,oc);
      fun(image,sr+1,sc,nc,oc);
      fun(image,sr,sc+1,nc,oc);
  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int oc = image[sr][sc];
        if(oc == newColor) return image;
        fun(image,sr,sc,newColor,oc);
        return image;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends