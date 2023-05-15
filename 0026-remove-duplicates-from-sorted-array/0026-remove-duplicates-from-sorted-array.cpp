class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        int prev=nums[0];
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(prev!=nums[i]){
                v.push_back(nums[i]);
                prev=nums[i];
            }
        }
        for(int i=0;i<v.size();i++){
            nums[i]=v[i];
        }
        return v.size();
    }
};