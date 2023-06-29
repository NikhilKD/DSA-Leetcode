class Solution {
public:
    int N=1e9+7;
    int f(int i,int n,vector<int>& loc,int fuel,vector<vector<int>> &dp){
        long long ans=0;
        if(fuel<0){
            return 0;
        }
        if(i==n){
            ans++;
        }
        if(dp[i][fuel]!=-1){
            return dp[i][fuel];
        }
        for(int j=0;j<loc.size();j++){
            int x=abs(loc[j]-loc[i]);
            if(j!=i){
                ans+=f(j,n,loc,fuel-x,dp)%N;
            }
        }
        return dp[i][fuel]=ans%N;
    }
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        vector<vector<int>> dp(loc.size()+1,vector<int> (fuel+1,-1));
        return f(start,finish,loc,fuel,dp);
    }
};

