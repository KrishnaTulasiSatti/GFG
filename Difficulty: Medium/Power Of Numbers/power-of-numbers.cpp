//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int fun(int a,int b) {
      if(b == 0) return 1;
      
      int ans = fun(a,b/2);
      if(b % 2 == 0) return ans*ans;
      else return ans*ans*a;
  }
    int reverseExponentiation(int n) {
        // code here
        int a = n;
        int b = (n == 10) ? 1 : n;
        int ans = fun(a,b);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends