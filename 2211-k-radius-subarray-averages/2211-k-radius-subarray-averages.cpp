class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n,-1);
        int j=0;
        int l=0;
        long long sum=0;
        k=k*2+1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(i-j+1>=k && j<=i){
                v[((i-j+1)/2)+l]=sum/k;
                sum-=nums[j];
                j++;
                l++;
            }
        }
        return v;
    }
};