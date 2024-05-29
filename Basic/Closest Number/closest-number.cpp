//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        // code here
        if(N % M == 0) return N;
        int ans1 = 0 , ans2 = 0;
        int temp = N;
        while(true) {
            N--;
            if(N % M == 0){
                ans1 = N;
                break;
            }
        }
        while(true) {
            N++;
            if(N % M == 0) {
                ans2 = N;
                break;
            }
        }
        if(temp > 0) {
            if(abs(temp-ans1) < abs(ans2-temp)) return ans1;
            else return ans2;
        }
        else{
            if(abs(temp-ans1) > abs(ans2-temp)) return ans2;
            else return ans1;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends