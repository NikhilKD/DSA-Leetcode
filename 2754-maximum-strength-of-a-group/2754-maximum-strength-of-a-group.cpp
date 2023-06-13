class Solution {
public:
    long long f(int i,long long pro,int n,vector<int>& nums,int size){
        if(i==n){
            if(size){
                return pro;
            }
            return INT_MIN;
        }
        long long nottake=f(i+1,pro,n,nums,size);
        long long take=f(i+1,pro*nums[i],n,nums,size+1);
        return max(take,nottake);
    }
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        return f(0,1,n,nums,0);
    }
};