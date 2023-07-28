class Solution {
public:
    int f(int i,int j,vector<int>& nums,bool turn){
        if(i>j){
            return 0;
        }
        if(turn){
            return max(nums[i]+f(i+1,j,nums,!turn),nums[j]+f(i,j-1,nums,!turn));
        }
        return min(f(i+1,j,nums,!turn),f(i,j-1,nums,!turn));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        int x=f(0,n-1,nums,true);
        cout<<x<<endl;
        return (tot-x)<=x;
    }
};