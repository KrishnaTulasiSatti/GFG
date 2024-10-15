//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(const Item &a,const Item &b) {
        double c1 = (double)a.value/(double)a.weight;
        double c2 = (double)b.value/(double)b.weight;
        return c1 > c2;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,cmp);
       // for(int i = 0 ; i < n ; i++) cout<<arr[i].value<<" "<<arr[i].weight; 
        double ans = 0;
        int weigh = 0;
        for(int i = 0 ; i < n ; i++) {
            
            if(arr[i].weight+weigh <= w) {
                weigh+=arr[i].weight;
                ans+=arr[i].value;
            }
            else{
                
                // 50 30+30 = 60
                int a = w-weigh;
                //cout<<a<<endl;
                ans+=((double)arr[i].value/(double)arr[i].weight)*a;
                break;
            }
           // cout<<ans<<endl;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends