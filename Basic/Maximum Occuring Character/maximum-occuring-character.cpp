//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        vector<int>frq(26,0);
        for(int i = 0 ; i < str.size() ; i++) frq[str[i]-'a']++;
        int max = *max_element(frq.begin(),frq.end());
        for(int i = 0 ; i < 26 ; i++) {
            if(frq[i] == max) return i+'a';
        }
        return -1;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends