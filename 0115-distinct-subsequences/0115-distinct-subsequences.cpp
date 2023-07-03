class Solution {
public:
    int mod=1e9+7;
    int numDistinct(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        int i=s1.length();
        int j=s2.length();
        for(int a=0;a<=i;a++){
            dp[a][0]=1;
        }
        for(int a=1;a<=i;a++){
            for(int b=1;b<=j;b++){
                if(s1[a-1]==s2[b-1]){
                    dp[a][b]=(dp[a-1][b-1]+dp[a-1][b])%mod;
                }else{
                    dp[a][b]=dp[a-1][b]%mod;
                }
            }
        }
        return dp[i][j];
    }
};