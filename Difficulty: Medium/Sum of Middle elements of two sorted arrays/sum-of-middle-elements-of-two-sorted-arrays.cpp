//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int x = arr1.size();
        int y = arr2.size();
        int mid = (x+y)/2;
        int flag = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        int s1 = 0;
        while(i < x && j < y) {
            if(arr1[i] < arr2[j]) {
                //cout<<arr1[i]<<endl;
                i++;
                k++;
                if(k == mid) {
                    s1 = arr1[i-1]; 
                   // cout<<s1<<" ";
                }
                else if(s1 != 0 && k >  mid)  {
                    s1+=arr1[i-1];
                     //cout<<s1<<" ";
                    break;
                }
                //cout<<s1<<endl;
            }
            else{
              //  cout<<arr2[j]<<endl;
                j++;
                k++;
                if(k == mid) {
                    s1 = arr2[j-1]; 
                   // cout<<s1<<" ";
                }
                else if(s1 != 0 && k > mid) {
                    s1+=arr2[j-1];
                    // cout<<s1<<" ";
                    break;
                }
               // cout<<s1<<endl;
            }
        }
        if(i == x && j < y) s1+=arr2[j];
        if(j == y && i < x) s1+=arr1[i];
        return s1;
        
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends