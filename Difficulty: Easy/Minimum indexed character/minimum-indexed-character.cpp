//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        vector<pair<int,int>>v(26);
        for(int i = 0 ; i < str.size() ; i++) {
            v[str[i]-'a'].first = 1;
        }
        for(int i = 0 ; i < patt.size() ; i++) {
            v[patt[i]-'a'].second = 1;
        }
        for(int i = 0 ; i < str.size() ; i++) {
            if(v[str[i]-'a'].first == 1 && v[str[i]-'a'].second == 1) return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends