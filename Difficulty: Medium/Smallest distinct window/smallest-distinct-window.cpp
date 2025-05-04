//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int mini = INT_MAX;
        
        unordered_map<int,int>m;
        for(auto it : str) m[it]++;
        
        unordered_map<int,int>m1;
        
        
        int l = 0;
        int r = 0;
        int cnt = 0;
        
        while(r < str.size()) {
            m1[str[r]]++;
            
            
            
            while(m1.size() == m.size() && l < str.size()) {
                mini = min(mini,r-l+1);
                
                // cout << mini << endl;
                // cout << l << " " << r << endl;
                m1[str[l]]--;
                if(m1[str[l]] == 0) m1.erase(m1.find(str[l]));
                l++;
                
            }
            
            
            r++;
            
        }
        
        return mini;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends