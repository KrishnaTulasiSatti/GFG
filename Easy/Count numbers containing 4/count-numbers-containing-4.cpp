//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int isFour(int n) {
        while(n) {
            int ld = n % 10;
            if(ld == 4) return 1;
            n/=10;
        }
        return 0;
    }
    int countNumberswith4(int n) {
        // code here
        int count =0 ;
        for(int i = 1 ; i <= n ; i++) {
            if(isFour(i)) count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends