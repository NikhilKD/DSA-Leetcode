class Solution {
public:
    int f(int p, int i, int m, vector<int> &piles, int n, vector<vector<vector<int>>> &dp) {
        if (i==n) return 0; // reached the end of piles
        if (dp[p][i][m]!=-1) return dp[p][i][m];
        int res = (p==0)?-1:INT_MAX, s=0; // intialize to maximize or minimize
        //NOTE: sum s is only for alice ! 
        for (int x = 1; x<=min(2*m, n-i); x++) { // 1<=x<=(2*m or till end of piles) 
            s += piles[i + x - 1]; // add one pile at a time for each recursion call
            if (p==0) { // alice's turn
                res = max(res, s + f(1, i+x, max(m, x),piles, n, dp));
            } else { // bob's turn
                res = min(res, f(0, i+x, max(m, x), piles, n, dp)); 
            }
        }
        return dp[p][i][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (n+1, vector<int> (n+1, -1)));
        return f(0, 0, 1, piles, n, dp);
    }
};