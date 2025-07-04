//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>>mat;
        for(int i = 0 ; i < row ; i++) {
            vector<int>m;
            for(int j = 0 ; j < col ; j++) {
                m.push_back(M[i][j]);
            }
            mat.push_back(m);
        }
        set<vector<int>>s;
        vector<vector<int>>res;
        for(int i = 0 ; i < row ; i++) {
            int size = s.size();
            s.insert(mat[i]);
            int newSize = s.size();
            if(size != newSize) res.push_back(mat[i]);
            
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends