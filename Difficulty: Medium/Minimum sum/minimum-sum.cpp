//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string s1,s2;
        int i = 0;
        while(i < arr.size()) {
            if(i % 2) s2+=(to_string(arr[i]));
            else s1+=(to_string(arr[i]));
            i++;
        }
        string ans;
       // cout<<s1<<endl;
      //  cout<<s2<<endl;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        i = 0;
        int j = 0;
        int carry = 0;
        while(i < s1.size() && j < s2.size()) {
            int s = (s1[i]-'0')+(s2[j]-'0')+carry;
           // cout<<s<<endl;
            if(s < 10) {
                ans+=(to_string(s));
                carry = 0;
            }
            else {
                int a = s % 10;
                int b = s/10;
                carry = b;
                ans+=(to_string(a));
            }
            i++;
            j++;
            
            
        }
        
        while(i < s1.size()) {
            int a = (s1[i]-'0')+carry;
            if(a < 10) {
                ans+=(to_string(a));
                carry = 0;
            }
            
            else{
                int x = a % 10;
                int y = a / 10;
                carry = y;
                ans+=(to_string(x));
            }
            i++;
        }
        
        while(j < s2.size()) {
            int a = (s2[j]-'0')+carry;
            if(a < 10) {
                ans+=(to_string(a));
                carry = 0;
            }
            
            else{
                int x = a % 10;
                int y = a / 10;
                carry =y;
                ans+=(to_string(x));
            }
            j++;
        }
        ans+=(to_string(carry));
        reverse(ans.begin(),ans.end());
     //   cout<<ans<<endl;
        
        i = 0;
        
        string res = "";
        while(ans[i] == '0') {
            i++;
        }
        for(int j = i ; j < ans.size() ; j++) res+=ans[j];
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends