// leetcode 1000

class Solution {
public:
int fun(int i,int j,vector<int>& stones,int k,vector<int>& prefix,vector<vector<int>> &dp){
if(i>=j){
    return 0;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
int ans=1e9;
int res = 1e9;
for(int t=i;t<j;t+=k-1){
ans = fun(i,t,stones,k,prefix,dp) + fun(t+1,j,stones,k,prefix,dp);
res = min(res,ans);
}
if((j-i)%(k-1)==0){
    if(i-1<0){
        res +=prefix[j];
    }
    else{
    res = res + prefix[j]-prefix[i-1];
    }
}
dp[i][j] =res;
return res;
}
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<int> prefix(n,0);
        prefix[0]= stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+ stones[i];
        }
        if(n==1){
            return 0;
        }
        if(n<k){
            return -1;
        }

        if((n-1)%(k-1)!=0){
            return -1;
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(0,n-1,stones,k,prefix,dp);
    }
};
