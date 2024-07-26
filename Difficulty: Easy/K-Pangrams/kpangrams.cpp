//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int frq[26] = {0};
        for(int i = 0 ; i < str.size() ; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') frq[str[i]-'a']++;
        }
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < 26 ; i++) {
            if(frq[i] > 1) sum+=(frq[i]-1);
            else if(frq[i] == 0) count++;
        }
        if(k < count) return false;
        if(sum < count) return false;
        if(sum-count >= 0) return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends