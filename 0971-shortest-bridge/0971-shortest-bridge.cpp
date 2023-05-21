class Solution {
public:
    void dfs(int i,int j,int n,vector<vector<int>>&grid,vector<vector<int>> &vis,queue<pair<int,int>> &q){
        int di[]={1,0,-1,0};
        int dj[]={0,+1,0,-1};
        vis[i][j]=1;
        q.push({i,j});
        for(int k=0;k<4;k++){
            int nexti=di[k]+i;
            int nextj=dj[k]+j;
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && grid[nexti][nextj] && !vis[nexti][nextj]){
                dfs(nexti,nextj,n,grid,vis,q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        bool flag=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !flag){
                    dfs(i,j,n,grid,vis,q);
                    flag=1;
                }
            }
            if(flag){
                break;
            }
        }
        int ans=0;
        flag=0;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int di[]={1,0,-1,0};
                int dj[]={0,+1,0,-1};
                for(int k=0;k<4;k++){
                    int nexti=di[k]+x;
                    int nextj=dj[k]+y;
                    if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !grid[nexti][nextj] && !vis[nexti][nextj]){
                        vis[nexti][nextj]=1;
                        q.push({nexti,nextj});
                    }
                    if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && grid[nexti][nextj] && !vis[nexti][nextj]){
                        flag=1;
                    }
                }
                
            }
            ans++;
            if(flag){
                break;
            }
        }
        return ans-1;
    }
};
