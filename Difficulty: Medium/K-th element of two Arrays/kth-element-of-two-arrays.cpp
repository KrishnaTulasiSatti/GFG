//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int a, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i = 0;
        int j = 0;
        int len = arr1.size()+arr2.size();
        int res[len];
        int k = 0;
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j]) res[k++] = arr1[i++];
            else res[k++] = arr2[j++];
        }
        while(i < arr1.size()) res[k++] = arr1[i++];
        while(j < arr2.size()) res[k++] = arr2[j++];
       // for(int i = 0 ; i < k ; i++) cout<<res[i]<<" ";
        return res[a-1];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends