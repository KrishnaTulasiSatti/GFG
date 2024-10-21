//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    vector<long long>neg;
    for(long long i = 0 ; i < K ; i++) {
        if(A[i] < 0) neg.push_back(A[i]);
    }
    vector<long long>ans;
    if(neg.size() == 0) ans.push_back(0);
    else ans.push_back(neg[0]);
    long long r = K;
    long long l = 0;
    int i = 0;
    while(r < N) {
        if(A[r] < 0) neg.push_back(A[r]);
        if(A[l] < 0) i++;
        if(i >= neg.size()) ans.push_back(0);
        else
        ans.push_back(neg[i]);
        l++;
        r++;
    }
    return ans;
    
                                                 
 }