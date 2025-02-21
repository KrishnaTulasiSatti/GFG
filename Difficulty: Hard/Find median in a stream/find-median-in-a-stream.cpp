//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        vector<double>res;
        
        multiset<int>low,high;
        
        
        auto balance = [&]() {
            
            if(low.size() > high.size()+1) {
                int val = *low.rbegin();
                high.insert(val);
                low.erase(low.find(val));
            }
            
            if(high.size() > low.size()) {
                int val = *high.begin();
                low.insert(val);
                high.erase(high.find(val));
            }
            
            
        };
        
        
        for(int i = 0 ; i < arr.size() ; i++) {
            if(low.empty() || arr[i] <= *low.rbegin()) low.insert(arr[i]);
            else high.insert(arr[i]);
            
            balance();
            
            if(low.size() > high.size()) {
                res.push_back((double)*low.rbegin());
            }
            else {
                res.push_back(((double)*low.rbegin()+(double)*high.begin())/2);
            }
        }
        
        return res;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends