//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        
        int cnt = 0;
        
        vector<int>pref(arr.size());
        pref[0] = arr[0];
        
        for(int i = 0 ; i < arr.size() ; i++) {
            pref[i] = pref[i-1]+arr[i];
        }
        
        unordered_map<int,int>m;
        m[0]++;
        
        for(int i = 0 ; i < pref.size() ; i++) {
            int x = pref[i];
            int need = x-k;
            
            if(m[need] > 0) cnt = cnt+m[need];
            
            m[x]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends