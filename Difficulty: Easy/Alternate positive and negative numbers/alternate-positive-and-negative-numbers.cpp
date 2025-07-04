//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] >= 0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        int i = 0;
        int j = 0;
        while(i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }
        while(i < pos.size()) ans.push_back(pos[i++]);
        while(j < neg.size()) ans.push_back(neg[j++]);
        arr = ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends