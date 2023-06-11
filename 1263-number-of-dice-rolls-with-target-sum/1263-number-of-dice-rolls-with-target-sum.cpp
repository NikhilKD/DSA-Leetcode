class Solution {
public:
    int M=1e9+7;
    long long f(int n,int k,int target,vector<vector<vector<int>>> &dp){
        if(target<0){
            return 0;
        }
        if(n==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp[n][k][target]!=-1){
            return dp[n][k][target];
        }
        cout<<n<<endl;
        long long ans=0;
        for(int i=1;i<=k;i++){
            ans+=f(n-1,k,target-i,dp);
        }
        ans=ans%M;
        return dp[n][k][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(target+1,-1)));
        return f(n,k,target,dp);
    }
};