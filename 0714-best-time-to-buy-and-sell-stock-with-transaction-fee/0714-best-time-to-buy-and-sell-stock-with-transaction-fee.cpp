class Solution {
public:
    int f(int i,vector<int>& prices,int fee,bool buy,vector<vector<int>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            profit=max(f(i+1,prices,fee,buy,dp),-prices[i]+f(i+1,prices,fee,!buy,dp));
        }
        if(!buy){
            profit=max(f(i+1,prices,fee,buy,dp),prices[i]-fee+f(i+1,prices,fee,!buy,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        bool buy=true;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,prices,fee,buy,dp);
    }
};