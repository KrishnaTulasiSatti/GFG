class Solution {
  public:
    
    vector<int> getSuff(vector<int>&arr,int n) {
         
        vector<int>suff(n);
        suff[n-1] = arr[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--) {
            int curr = suff[i+1] + arr[i];
            if(curr > arr[i]) suff[i] = curr;
            else suff[i] = arr[i];
        }
        
        return suff;
        
    }
    
    vector<int> getPref(vector<int>&arr,int n) {
        
        vector<int>pref(n);
        pref[0] = arr[0];
        
        for(int i = 1 ; i < n ; i++) {
            int curr = pref[i-1] + arr[i];
            if(curr < arr[i]) pref[i] = curr;
            else pref[i] = arr[i];
        }
        
        return pref;
        
    }
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        
        int n = arr.size();
      
        vector<int>pref = getPref(arr,n);
        vector<int>suff = getSuff(arr,n);
        
        vector<int>maxi(n);
        vector<int>mini(n);
        
        maxi[n-1] = suff[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--) {
            maxi[i] = max(maxi[i+1],suff[i]);
        }
        
        mini[0] = pref[0];
        
        for(int i = 1 ; i < n ; i++) {
            mini[i] = min(mini[i-1],pref[i]);
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n-1 ; i++) {
            ans = max(abs(mini[i]-maxi[i+1]),ans);
        }
        
        reverse(arr.begin(),arr.end());
    
        vector<int>pref2 = getPref(arr,n);
        vector<int>suff2 = getSuff(arr,n);
    
        
        // reverse(pref2.begin(),pref2.end());
        // reverse(suff2.begin(),suff2.end());
        
        vector<int>mx1(n);
        vector<int>mn1(n);
        
        mx1[n-1] = suff2[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--) {
            mx1[i] = max(mx1[i+1],suff2[i]);
        }
        
        mn1[0] = pref2[0];
        
        for(int i = 1 ; i < n ; i++) {
            mn1[i] = min(mn1[i-1],pref2[i]);
        }
        
        // for(auto& it : mx1) cout << it << " ";
        // cout << endl;
        
        // for(auto& it : mn1) cout << it << " ";
        // cout << endl;
        
        for(int i = 0 ; i < n-1 ; i++) {
            ans = max(abs(mn1[i]-mx1[i+1]),ans);
            // cout << abs(mn1[i]-mx1[i+1]) << "--";
        }
    
        
        return ans;
    }
};