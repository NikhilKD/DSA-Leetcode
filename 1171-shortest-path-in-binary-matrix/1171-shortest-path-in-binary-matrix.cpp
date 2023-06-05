class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1){
            return -1;
        }
        vector<vector<int>> dis(n,vector<int>(n,1e5));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        dis[0][0]=1;
        int dj[]={0,1,1,1,0,-1,-1,-1};
        int di[]={1,1,0,-1,-1,-1,0,1};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int xi=x.first.first+di[i];
                int xj=x.first.second+dj[i];
                int dist=x.second;
                if(xi>=0 && xj>=0 && xi<n && xj<n && !grid[xi][xj] && dist+1<dis[xi][xj]){
                    dis[xi][xj]=dist+1;
                    q.push({{xi,xj},dist+1});
                }
            }
        }
        return dis[n-1][n-1]==1e5?-1:dis[n-1][n-1];
    }
};