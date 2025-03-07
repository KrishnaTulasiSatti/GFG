//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    string captain(int N){
        // code here
        if(N % 3 == 0) return "JACK";
        else return "JELLY";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.captain(N)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends