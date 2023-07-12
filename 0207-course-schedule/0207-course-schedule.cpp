class Solution {
public:
    bool ans(int j,vector<vector<int>> &adj,vector<int> &vis,vector<int> &pvis){
        vis[j]=1;
        pvis[j]=1;
        for(auto i:adj[j]){
            if(!vis[i]){
                if(ans(i,adj,vis,pvis)){
                    return true;
                }
            }else if(pvis[i]){
                return true;
            }
        }
        pvis[j]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(1e5);
        vector<int> vis(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        bool yes=false;
        for(int i=0;i<n;i++){
            vector<int> pvis(n,0);
            if(!vis[i]){
                if(ans(i,adj,vis,pvis)){
                    yes=true;
                    break;
                }
            }
        }
        if(yes){
            return false;
        }else{
            return true;
        }
    }
};     


 