//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i = 0 ; i <= n/2 ; i++) {
	        int a = i;
	        int b = n-i;
	      //  cout << a << " " << b << endl;
	        int c = __builtin_popcount(a);
	        int d = __builtin_popcount(b);
	      //  cout << c << " " << d << endl;
	        if(b == c || a == d) return 0;
	    }
	    return 1;
	}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends