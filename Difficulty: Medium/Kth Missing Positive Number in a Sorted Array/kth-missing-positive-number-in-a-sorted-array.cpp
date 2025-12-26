class Solution {
public:
    int kthMissing(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size(); 

        while (low <= high) {
            
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans < arr.size()) {
            return k + ans;
        }

        return arr.back() + (k - (arr.back() - arr.size()));
    }
};
