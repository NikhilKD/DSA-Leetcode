class Solution {
public:
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        // cout<<i<<" "<<j<<endl;
        if(i>=s1.length()){
            int sum=0;
            for(int k=j;k<s2.length();k++){
                sum+=s2[k];
            }
            return sum;
        }
        if(j>=s2.length()){
            int sum=0;
            for(int k=i;k<s1.length();k++){
                sum+=s1[k];
            }
            return sum;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=1e9+7;
        if(s1[i]==s2[j]){
            take=f(i+1,j+1,s1,s2,dp);
        }
        int nottake1=s1[i]+f(i+1,j,s1,s2,dp);
        int nottake2=s2[j]+f(i,j+1,s1,s2,dp);
        return dp[i][j]=min({take,nottake1,nottake2});
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        return f(0,0,s1,s2,dp);
    }
};