class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto i:nums){
            if(i>=0){
                pos.push_back(i);
            }else{
                neg.push_back(i);
            }
        }
        int i=0;
        int j=0;
        int k=0;
        while(k<nums.size()){
            if(k%2){
                nums[k]=neg[j];
                k++;
                j++;
            }else{
                nums[k]=pos[i];
                k++;
                i++;
            }
        }
        return nums;
    }
};