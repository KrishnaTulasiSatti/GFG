//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>res;
        int i = 0;
        int j = arr.size()-1;
        int flag = 0;
        while(i <= j) {
            if(flag == 0) res.push_back(arr[i++]);
            else res.push_back(arr[j--]);
            flag = !flag;
        }
        long long sum = 0;
        for(int i = 0 ; i < res.size()-1 ; i++) {
            sum+=abs(res[i]-res[i+1]);
        }
        sum+=abs(res[0]-res[res.size()-1]);
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends