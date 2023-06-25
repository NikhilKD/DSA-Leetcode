class Solution {
public:
    int dp[101][201];

    int getans(int i, int fuel, int finish, vector<int>& loc){
        if(fuel < 0) return 0;
        if(dp[i][fuel] != -1) return dp[i][fuel];

        int ans = 0;
        if(i == finish) ans++;
        
        for(int j = 0; j < loc.size(); j++){
            if(i != j) ans = (ans + getans(j, fuel - abs(loc[i] - loc[j]), finish, loc)) % 1000000007;
        }
        return dp[i][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof dp);
        return getans(start, fuel, finish, locations);

    }
};