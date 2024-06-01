//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        unordered_map<int,int>m;
        for(auto it : s) m[it]++;
        int odd = 0 , even = 0;
        for(auto it : m) {
            int pos = (it.first-'a')+1;
            if(pos % 2 == 0 && it.second % 2 == 0) even++;
            else if(pos % 2 == 1 && it.second % 2 == 1) odd++;
        }
        int sum = even+odd;
        if(sum % 2) return "ODD";
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends