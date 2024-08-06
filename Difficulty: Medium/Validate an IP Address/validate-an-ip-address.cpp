//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int check(string x) {
      // cout<<x.size()<<" ";
      if(x.size() > 1 && x[0] == '0') return false;
      int n = stoi(x);
      if(n >= 0 && n <= 255) return true;
      return false;
  }
    int isValid(string str) {
        // code here
        
        int i = 0;
        string x1 = "";
        string x2 = "";
        string x3 = "";
        string x4 = "";
        while(i < str.size() && str[i] != '.'){
            x1+=str[i];
            i++;
        }
       // cout<<x1<<" ";
        if(str[i] == '.') i++;
        if(x1 == "" || x1.size() > 3) return false;
        else if(!check(x1)) return false;
        while(i < str.size() && str[i] != '.'){
            x2+=str[i];
            i++;
        }
       // cout<<x2<<" ";
        if(str[i] == '.') i++;
        if(x2 == "" || x2.size() > 3) return false;
         else if(!check(x2)) return false;
        while(i < str.size() && str[i] != '.'){
            x3+=str[i];
            i++;
        }
      //  cout<<x3<<" ";
        if(str[i] == '.') i++;
        if(x3 == "" || x3.size() > 3) return false;
        else if(!check(x3)) return false;
         while(i < str.size() && str[i] != '.'){
            x4+=str[i];
            i++;
        }
        if(i != str.size()) return false;
        if(x4 == "" || x4.size() > 3) return false;
        else if(!check(x4)) return false;
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends