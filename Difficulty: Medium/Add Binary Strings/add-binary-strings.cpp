//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string res;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int i = 0 , j = 0;
        int carry = 0;
        int sum = -1;
        while(i < s1.size() && j < s2.size()) {
            int a = s1[i]-'0';
            int b = s2[j]-'0';
            sum = a+b+carry;
            if(sum == 2) {
                sum = 0;
                carry = 1;
            }
            else if(sum == 3) {
                sum = 1;
                carry = 1;
            }
            else carry = 0;
            res+=(sum+'0');
            i++;
            j++;
        }
        //cout<<i<<" "<<j<<endl;
        while(i < s1.size()) {
            int a = s1[i]-'0';
            sum = a+carry;
          //  cout<<sum<<endl;
            if(sum == 2) {
                sum = 0;
                carry = 1;
            }
            else if(sum == 3) {
                sum = 1;
                carry = 1;
            }
            else carry = 0;
            res+=(sum+'0');
            i++;
           // cout<<sum<<" "<<carry<<" "<<res<<endl;
        }
       // cout<<res<<endl;
        while(j < s2.size()) {
            int a = s2[j]-'0';
            sum = a+carry;
            if(sum == 2) {
                sum = 0;
                carry = 1;
            }
            else if(sum == 3) {
                sum = 1;
                carry = 1;
            }
            else carry = 0;
            res+=(sum+'0');
            j++;
        }
        if(carry != 0) res+=(carry+'0');
        reverse(res.begin(),res.end());
        string ans = "";
        int k = 0;
       // cout<<res[0]<<endl;
        while(res[k] == '0') {
            k++;
        }
        //cout<<k<<endl;
        for(int j = k ; j < res.size() ; j++) ans+=res[j];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends