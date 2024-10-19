//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        int ld = str[n-1]-'0';
        //cout<<ld<<" ";
        if(ld <= 5) {
            str[n-1] = '0';
            //cout<<str;
            return str;
        }
        else{
            str[n-1] = '0';
            int carry = 1;
            for(int i = n-2 ; i >= 0 ; i--) {
                int d = str[i]-'0'+carry;
                if(d < 10) {
                    str[i] = d+'0';
                    carry = 0;
                }
                else{
                    int a = d % 10;
                    str[i] = a+'0';
                    carry = d/10;
                }
            }
            string ans;
            if(carry) ans = to_string(carry)+str;
            else ans = str;
            return ans;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends