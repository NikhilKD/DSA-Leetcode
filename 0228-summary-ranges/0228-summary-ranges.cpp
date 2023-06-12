class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(nums.size()==0){
            return v;
        }
        int start=nums[0];
        int end=nums[0];
        int i=0;
        int k=0;
        int j=i+1;
        string s="";
        string e="";
        while(i<j && j<nums.size()){
            if(nums[k]+1==nums[j]){
                k++;
                j++;
            }else{
                start=i;
                end=k;
                if(start==end){
                    v.push_back(to_string(nums[start]));    
                }else{
                    v.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                }
                i=j;
                k=i;
                j+=1;
            }
        }
        if(i==k){
            v.push_back(to_string(nums[i]));
        }else{
            v.push_back(to_string(nums[i])+"->"+to_string(nums[k]));
        }
        return v;
    }
};
