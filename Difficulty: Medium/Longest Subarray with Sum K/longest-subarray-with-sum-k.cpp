//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
        
        // int sum = 0;
        // int l = 0;
        // int r = 0;
        // int maxi = 0;
        // while(r < arr.size()) {
        //     sum+=arr[r];
        //     while(sum > k && l < arr.size()) {
        //         sum-=arr[l];
        //         l++;
        //     }
        //     if(sum == k) {
        //         maxi = max(maxi,r-l+1);
        //     }
        //     r++;
        // }
        // return maxi; If the values are greater than zero(0);
        
        
        unordered_map<long long,int>m;
        m[0] = -1;
        int maxi = 0;
        
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            
            sum+=arr[i];
            
            int need = sum-k;
            
            if(m.find(need) != m.end()) {
                maxi = max(maxi,i-m[need]);
            }
            
            // [2,0,0,3] --> We have to find the most left index to get maximum length
            // So if the sum doesn't exist in map,then only update the value else do not update the value
            // as it decreases the length of the subarray
            
            
            if(m.find(sum) == m.end()) {
                m[sum] = i;
            }
            
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends