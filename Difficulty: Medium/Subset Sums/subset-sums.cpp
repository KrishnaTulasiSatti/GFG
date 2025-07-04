//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
vector<int>res;
void fun(vector<int>&arr,int i,int n,int sum) {
    if(i == n) return;
    //not pick
    fun(arr,i+1,n,sum);
  //  res.push_back(sum);
    sum+=arr[i];
    fun(arr,i+1,n,sum);
    res.push_back(sum);
    
    
}
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        res.push_back(0);
        fun(arr,0,arr.size(),0);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends