//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i = 0;
        int j = 0;
        int ch = 0;
        int res = 0;
        while(i < a.size() && j < b.size()) {
            if(ch == k) return res;
            
            if(a[i] < b[j]) res = a[i++];
            else res = b[j++];
            
            ch++;
            
        }
        
        while(i < a.size()) {
            if(ch == k) return res;
            res = a[i++];
            ch++;
        }
        
        while(j < b.size()) {
            if(ch == k) return res;
            res = b[j++];
            ch++;
        }
        return res;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends