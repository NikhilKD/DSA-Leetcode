class Solution {
public:
    vector<int> ans;
    void f(int i,int n,vector<int> &nums,int prev,vector<int> &v,vector<int> &dp){
        if(i==n){
            if(ans.size()<v.size()){
                ans=v;
            }
            return;
        }
        if(v.size()==0){
            dp[i]=v.size();
            v.push_back(nums[i]);
            f(i+1,n,nums,i,v,dp);
            v.pop_back();
        }else if((int)v.size()>dp[i] && nums[i]%nums[prev]==0){
            dp[i]=v.size();
            v.push_back(nums[i]);
            f(i+1,n,nums,i,v,dp);
            v.pop_back();
        }
        f(i+1,n,nums,prev,v,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,-1);
        f(0,n,nums,1,v,dp);
        return ans;    
    }
};