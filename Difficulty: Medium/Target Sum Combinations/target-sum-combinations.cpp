class Solution {
  public:
  
  vector<vector<int>>res;

    void fun(vector<int>&candidates,int i,int n,int target,int sum,vector<int>&ans) {

        if(i == n) {
            if(sum == target) res.push_back(ans);
            return;
        }

        if(sum > target) return;
        
        
        ans.push_back(candidates[i]);
        fun(candidates,i,n,target,sum + candidates[i],ans);
        ans.pop_back();

        fun(candidates,i+1,n,target,sum,ans);

    }
    vector<vector<int>> targetSumComb(vector<int> &candidates, int target) {
        // code here
        int n = candidates.size();

        vector<int>temp;

        fun(candidates,0,n,target,0,temp);

        return res;
    }
};