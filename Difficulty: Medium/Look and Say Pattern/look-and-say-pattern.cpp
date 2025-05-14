//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string res = "1";
    string fun(int n) {
        if(n == 1) return "1";
        
        string str = fun(n-1);
        
        string newstr = "";
        
        int cnt = 0;
        
        for(int i = 0 ; i < str.size() ; i++) {
            
            if(str[i] != str[i+1]) {
                newstr += (to_string(cnt+1))+str[i];
                cnt = 0;
            }
            else cnt++;
        }
        
        return newstr;
        
    }
    string countAndSay(int n) {
        
        return fun(n);
        // code here
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends