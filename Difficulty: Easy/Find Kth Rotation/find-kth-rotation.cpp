class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ind = min_element(arr.begin(),arr.end())-arr.begin();
        return ind;
    }
};
