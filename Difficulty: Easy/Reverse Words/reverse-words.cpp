//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string res = "";
        string s = "";
        for(int i = 0 ; i < str.size() ; i++) {
            if(str[i] == '.') {
                reverse(s.begin(),s.end());
                res+=s+".";
                s = "";
            }
            else {
                s+=str[i];
            }
        }
        reverse(s.begin(),s.end());
        res+=s;
        reverse(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends