class Solution {
public:
    int check(string &s){
        int i=0;
        int j=s.length()-1;
        // cout<<s<<endl;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int j,string &s,vector<int> &dp){
        if(i==j){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp="";
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            temp+=s[k];
            if(check(temp)){
                mini=min(mini,1+f(k+1,j,s,dp));
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;      
    }
};
