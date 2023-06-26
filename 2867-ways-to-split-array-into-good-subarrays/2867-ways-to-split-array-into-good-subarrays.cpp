class Solution {
public:
    int N=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        queue<int> q;
        int ans=1;
        bool one=false;
        for(int i=0;i<n;i++){
            if(nums[i]){
                one=true;
            }
            q.push(nums[i]);
            sum+=nums[i];
            while(!q.empty() && sum>1){
                sum-=q.front();
                q.pop();
                if(sum==1){
                    ans=(ans*q.size())%N;
                }
            }
        }
        return one?ans:0;
    }
};