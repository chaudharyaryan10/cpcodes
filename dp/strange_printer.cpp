// leetcode 664

// There is a strange printer with the following two special properties:
// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.

class Solution {
public:
   int fun(string &s,int l,int r, vector<vector<int>> &dp){
      if(l==r){
        return 1;
      }
      if(l>r){
        return 0;
      }
if(dp[l][r]!=-1){
    return dp[l][r];
}
      int newid =l;
      for(int j=l+1;j<=r;j++){
        if(s[j]==s[l]){
            newid = j;
        }
        else{
            break;
        }
      }
      if(newid == r){
        return 1;
      }
      int ans1= 1+ fun(s,newid+1,r,dp);
      int ans2= INT_MAX;
      for(int j=newid+1;j<=r;j++){
        if(s[j] == s[l]){
         int ans = fun(s,newid+1,j-1,dp) + fun(s,j,r,dp);
         ans2 = min(ans2,ans);
        }
      }
      dp[l][r] =min(ans1,ans2);
      return min(ans1,ans2);
     
   }
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(s,0,n-1,dp);
    }
};
