
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int fun(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
      if(i>=j){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int ans = 1e9;
      int res = 1e9;
      for(int k=i;k<j;k++){
          ans = arr[i-1]*arr[k]*arr[j] + fun(i,k,arr,dp) + fun(k+1,j,arr,dp);
          res = min(res,ans);
      }
      dp[i][j] = res;
      return res;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(1,n-1,arr,dp);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}
