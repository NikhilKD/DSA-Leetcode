class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long sum1=nums[i]+nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum2=nums[l]+nums[r];
                    if(sum1+sum2==target){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        if(find(ans.begin(),ans.end(),v)==ans.end()){
                        ans.push_back(v);
                        }
                        l++;
                        r--;
                    }else if(sum1+sum2>target){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};