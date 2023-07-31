class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int ans=0;
        string x="";
        x+=s[0];
        for(int k=1;k<n;k++){
            int j=k;
            for(int i=0;i<n,j<n;i++,j++){
                if(k==1){
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i][j]+1;
                        ans=max(ans,j-i+1);
                        x=s.substr(i,j-i+1);
                    } 
                }else{
                    if(dp[i+1][j-1]>0 && s[i]==s[j]){
                        dp[i][j]=dp[i][j-1]+1;
                        ans=max(ans,j-i+1);
                        x=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return x;
    }
};