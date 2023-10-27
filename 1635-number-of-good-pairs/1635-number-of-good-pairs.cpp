class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        int count=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(m.find(nums[i])!=m.end()){
                count+=m[nums[i]];
            }
            m[nums[i]]++;
        }
        return count;
    }
};