class Solution {
public:
    int ans=0;
    bool check(unordered_map<int,int> &mp,int tar){
        int c=0;
        int a=tar,b=tar+1;
        for(auto it:mp){
            int num=it.second;
            if(num==a || num==b){
                c++;
                continue;
            }
            int g=num/b;
            int rem=num%b;
            if(rem==0){
                c+=g;
                continue;
            }
            int req=a-rem;
            if(g>=req)
            c+=g+1;
            else
            return false;
        }
        ans=c;
        return true;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int mini=INT_MAX;
        for(auto it:mp){
            mini=min(mini,it.second);
        }
        for(int i=mini;i>=1;i--){
            if(check(mp,i))
            return ans;
        }
        return -1;
    }
};