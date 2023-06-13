class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n && nums[i]!=0){
            i++;
        }
        int j=i+1;
        while(j<n){
            while(j<n && nums[j]==0){
                j++;
            }
            if(j>=n){
                break;
            }
            swap(nums[i],nums[j]);
            while(i<n && nums[i]!=0){
                i++;
            }
            j=i+1;
        }
    }
};
