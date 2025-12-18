class Solution {
  public:
  
    static bool cmp(const int &a,const int &b) {
        
        if((a % 2 == 0 && b % 2 == 0)) return a < b;
        else if((a % 2 == 1 && b % 2 == 1)) return a > b;
        else if((a % 2 == 0 && b % 2 == 1)) return false;
        else return true;
    }
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),cmp);
    }
};