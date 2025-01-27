// leetcode 312
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

class Solution {
public:
int fun(int l,int r,vector<int>& nums,int left,int right,vector<vector<int>>& dp){
    if(l==r){
        return nums[l]*left*right;
    }
    if(l>r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=INT_MIN;
    int res=INT_MIN;
  for(int j=l;j<=r;j++){
    ans=nums[j]*left*right + fun(l,j-1,nums,left,nums[j],dp) + fun(j+1,r,nums,nums[j],right,dp);
    res = max(res,ans);
  }
  dp[l][r] = res;
  return res;
}
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(0,n-1,nums,1,1,dp);
    }
};
