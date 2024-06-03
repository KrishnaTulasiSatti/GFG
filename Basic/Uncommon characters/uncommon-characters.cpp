//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            string res = "";
            for(int i = 0 ; i < A.size() ; i++) {
                if(B.find(A[i]) == string::npos) {
                    if(res.find(A[i]) == string::npos) res+=A[i];
                }
            }
            for(int i = 0 ; i < B.size() ; i++) {
                if(A.find(B[i]) == string::npos) {
                    if(res.find(B[i]) == string::npos) res+=B[i];
                }
            }
            sort(res.begin(),res.end());
            if(res == "") res+="-1";
            return res;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends