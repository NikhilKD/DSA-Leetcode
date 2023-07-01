class Solution {
public:
    int f(int i,int n,vector<int> v,vector<int> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake=f(i+1,n,v,dp);
        int take=i*v[i]+f(i+2,n,v,dp);
        return dp[i]=max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v(nums[n-1]+1,0);
        for(auto i:nums){
            v[i]++;
        }
        vector<int> dp(nums[n-1]+1,-1);
        return f(nums[0],nums[n-1]+1,v,dp);
        // return 0;
    }
};