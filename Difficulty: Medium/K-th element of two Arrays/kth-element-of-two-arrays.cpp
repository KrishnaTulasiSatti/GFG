class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        // code here
        int m = nums1.size();
        int n = nums2.size();

        if(n < m) return kthElement(nums2,nums1,k);

        int low = max(0, k - n); 
        int high = min(k, m);


        int cnt = k;

        while(low <= high) {

            int mid1 = (low + high)/2;

            int mid2 = cnt-mid1;

          //  cout << mid1 << "--" << mid2 << endl;

            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;

            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];

            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];

         //   cout << l1 << " " << l2 << "-->" << r1 << " " << r2 << endl;

            if(l1 <= r2 && l2 <= r1) {
                return max(l1,l2);
            }
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }

        return -1;
        
    }
};