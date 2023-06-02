class Solution {
public:
    void dfs(int i,vector<vector<int>> &adj,vector<int> &vis,int &count){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                count++;
                dfs(j,adj,vis,count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                float dis=sqrt(pow((bombs[i][0]-bombs[j][0]),2)+pow((bombs[i][1]-bombs[j][1]),2));
                if(dis<=(float)bombs[i][2]){
                    adj[i].push_back(j);
                }
                if(dis<=(float)bombs[j][2]){
                    adj[j].push_back(i);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int count=1;
            dfs(i,adj,vis,count);
            maxi=max(maxi,count);
        }
        return maxi;
    }
};