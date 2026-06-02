class Solution {
  public:
    
    int merge(vector<int>&arr,int l,int m,int h) {
        
        vector<int>ans;
        
        int i = l;
        int j = m+1;
        
        int cnt = 0;
        
        while(i <= m && j <= h) {
            if(arr[i] <= arr[j]) {
                ans.push_back(arr[i++]);
            }
            else {
                cnt += m-i+1;
                ans.push_back(arr[j++]);
            }
        }
        
        while(i <= m) ans.push_back(arr[i++]);
        while(j <= h) ans.push_back(arr[j++]);
        
        int k = 0;
        
        for(int i = l ; i <= h ; i++) {
            arr[i] = ans[k++];
        }
        
        return cnt;
    }
    int mergeSort(vector<int>&arr,int l,int h) {
        
        if(l >= h) return 0;
        
        int mid = (l+h)/2;
        
        int cnt = 0;
        cnt += mergeSort(arr,l,mid);
        cnt += mergeSort(arr,mid+1,h);
        
        cnt += merge(arr,l,mid,h);
        
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        
        int n = arr.size();
        
        int res = mergeSort(arr,0,n-1);
        return res;
    }
};