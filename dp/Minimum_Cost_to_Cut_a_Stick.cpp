class Solution {
public:
   int fun(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
     if(i>j){
        return 0;
     }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     int ans = 1e9;
     int res = 1e9;
     for(int k=i;k<=j;k++){
         ans = (cuts[j+1] - cuts[i-1])  + fun(i,k-1,cuts,dp) + fun(k+1,j,cuts,dp);
         res = min(res,ans);
     }
     dp[i][j] =res;
    return res;
   }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());
        return fun(1,m-2,cuts,dp);
    }
};
